#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define N 200001
using namespace std;
set<int>q[N];
int res=0;
int check(int x){return q[x].empty() || (*q[x].rbegin()<x);}
int main()
{
    int t=1;
    while(t --> 0)
    {
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            q[x].insert(y);q[y].insert(x);
        }
        for(int i=1;i<=n;i++) res+=check(i);
        // for(int i=1;i<=n;i++) printf("%d ",ans[i]);puts("");
        int Q;scanf("%d",&Q);
        while(Q --> 0)
        {
            int op,x,y;
            scanf("%d",&op);
            if(op==3){printf("%d\n",res);continue;}
            if(op==2)
            {
                scanf("%d%d",&x,&y);
                res-=check(x);res-=check(y);
                q[x].erase(y);q[y].erase(x);
                res+=check(x);res+=check(y);
            }
            else
            {
                scanf("%d%d",&x,&y);
                res-=check(x);res-=check(y);
                q[x].insert(y);q[y].insert(x);
                res+=check(x);res+=check(y);
            }
        }
    }
    return 0;
}