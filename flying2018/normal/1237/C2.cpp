#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#define N 50010
#define fi first
#define se second
using namespace std;
struct node{
    int x,y,z;
}p[N];
bool chs[N];
map<int,map<int,map<int,int> > >q;
void erase(node p)
{
    q[p.x][p.y].erase(p.z);
    if(q[p.x][p.y].empty()) q[p.x].erase(p.y);
    if(q[p.x].empty()) q.erase(p.x);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z),q[p[i].x][p[i].y][p[i].z]=i;
    for(int i=1;i<=n;i++)
    if(!chs[i])
    {
        int k=0;
        chs[i]=true;
        erase(p[i]);
        auto x=q.lower_bound(p[i].x);
        if(x==q.end()) --x;
        auto y=x->se.lower_bound(p[i].y);
        if(y==x->se.end()) --y;
        auto z=y->se.lower_bound(p[i].z);
        if(z==y->se.end()) --z;
        int u=z->se;
        erase(p[u]);
        chs[u]=true;
        printf("%d %d\n",i,u);
    }
    return 0;
}