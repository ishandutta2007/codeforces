#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int vN, eN;
int output[200005], prio[200005], prioN;
vector<pair<int, int> > edge[200005];
int a[200005], b[200005], c[200005];

queue<int> ready;

int main()
{
    scanf("%d%d", &vN, &eN);
    for(int i=0; i < eN; ++i){
        scanf("%d%d%d", a+i, b+i, c+i);
        --a[i];
        --b[i];
        output[a[i]] += c[i];
        output[b[i]] += c[i];
        edge[a[i]].push_back(make_pair(b[i], c[i]));
        edge[b[i]].push_back(make_pair(a[i], c[i]));
    }
    ready.push(0);
    prio[0]=0;
    prioN=1;
    while(!ready.empty()){
        int f=ready.front();
        ready.pop();
        for(int i=0; i < edge[f].size(); ++i){
            pair<int, int> p=edge[f][i];
            output[p.first] -= 2*p.second;
            if(!output[p.first] && p.first != vN-1 && p.first != 0){
                ready.push(p.first);
                prio[p.first]=prioN++;
            }
        }
    }
    prio[vN-1]=vN-1;
    for(int i=0; i < eN; ++i){
        if(prio[a[i]] < prio[b[i]])
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}