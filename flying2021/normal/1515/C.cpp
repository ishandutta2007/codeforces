#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define N 100010
using namespace std;
int n,m,x;
int h[N],id[N];
struct node{
    int u,v;
    bool operator <(const node a)const{return v>a.v;}
};
void clear(){}
void solve()
{
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    priority_queue<node>q;
    for(int i=1;i<=m;i++) q.push((node){i,0});
    puts("YES");
    for(int i=1;i<=n;i++)
    {
        node u=q.top();q.pop();
        printf("%d ",u.u);
        q.push((node){u.u,u.v+h[i]});
    }
    puts("");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0){solve();clear();}
    return 0;
}