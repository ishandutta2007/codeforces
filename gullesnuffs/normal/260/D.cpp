#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int color[100005], sum[100005], first[2], cN[2];
priority_queue<pair<int, int> > s[2];
bool visited[100005];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%d%d", color+i, sum+i);
        visited[i]=0;
        s[color[i]].push(make_pair(-sum[i], i));
        first[color[i]]=i;
        cN[color[i]]++;
    }
    int edgeN=0;
    while(edgeN < n-1){
        pair<int, int> p, q;
        if(s[1].empty()){
            q=make_pair(0, first[1]);
            p=s[0].top();
            s[0].pop();
        }
        else if(s[0].empty()){
            q=make_pair(0, first[0]);
            p=s[1].top();
            s[1].pop();
        }
        else if(-s[0].top().first < -s[1].top().first){
            p=s[0].top();
            q=s[1].top();
            s[0].pop();
        }
        else{
            p=s[1].top();
            q=s[0].top();
            s[1].pop();
        }
        if(visited[p.second])
            continue;
        if(cN[color[p.second]] == 1){
            pair<int, int> pp=p;
            p=q;
            q=pp;
            while(visited[p.second]){
                p=s[color[p.second]].top();
                s[color[p.second]].pop();
            }
        }
        while(visited[q.second]){
            q=s[color[q.second]].top();
            s[color[q.second]].pop();
        }
        visited[p.second]=1;
        --cN[color[p.second]];
        printf("%d %d %d\n", p.second+1, q.second+1, -p.first);
        sum[q.second] -= -p.first;
        s[color[q.second]].push(make_pair(-sum[q.second], q.second));
        ++edgeN;
    }
    return 0;
}