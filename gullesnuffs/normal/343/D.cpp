#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<int> adj[500005];
int stop[500005];
int posInTree[500005];

struct MaxTree{
    int a[1101000];
    void fillSet(int from, int to, int val){
        from += 1<<19;
        to += 1<<19;
        while(to > from){
            a[from]=val;
            if(from%2 == 0 && from<to-1){
                a[from+1]=val;
                a[from/2]=val;
            }
            if(to%2)
                a[to-1]=val;
            from=from/2+1;
            to=to/2;
        }
    }
    void emptySet(int pos, int val){
        pos += 1<<19;
        while(pos > 0){
            a[pos]=val;
            pos /= 2;
        }
    }
    int emptyQuery(int from, int to){
        from += 1<<19;
        to += 1<<19;
        int res=-1;
        while(to > from){
            res=max(a[from], res);
            if(from%2 == 0 && from<to-1){
                res=max(a[from+1], res);
                res=max(a[from/2], res);
            }
            if(to%2)
                res=max(a[to-1], res);
            from=from/2+1;
            to=to/2;
        }
        return res;
    }
    int fillQuery(int pos){
        int res=0;
        pos += 1<<19;
        while(pos > 0){
            if(a[pos] > res)
                res=a[pos];
            pos /= 2;
        }
        return res;
    }
}fillTree, emptyTree;

int main()
{
    scanf("%d", &n);
    for(int i=0; i < n-1; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i < (1<<20); ++i)
        emptyTree.a[i]=1;
    stack<pair<int, int> > s;
    s.push(make_pair(0, 0));
    int pos=2;
    posInTree[0]=1;
    while(!s.empty()){
        pair<int, int> t=s.top();
        s.pop();
        if(t.second == adj[t.first].size()){
            stop[t.first]=pos;
            continue;
        }
        s.push(make_pair(t.first, t.second+1));
        pair<int, int> New=make_pair(adj[t.first][t.second], 0);
        if(posInTree[New.first])
            continue;
        s.push(New);
        posInTree[New.first]=pos++;
    }
    for(int i=0; i < n; ++i){
        --posInTree[i];
        --stop[i];
    }
    int q;
    scanf("%d", &q);
    for(int i=0; i < q; ++i){
        int c, v;
        scanf("%d%d", &c, &v);
        if(c == 1){
            //Fill
            fillTree.fillSet(posInTree[v-1], stop[v-1], i+2);
        }else if(c == 2){
            //Empty
            emptyTree.emptySet(posInTree[v-1], i+2);
        }else{
            int lastEmpty=emptyTree.emptyQuery(posInTree[v-1], stop[v-1]);
            int lastFill=fillTree.fillQuery(posInTree[v-1]);
            if(lastFill > lastEmpty)
                printf("1\n");
            else
                printf("0\n");
        }
    }
    return 0;
}