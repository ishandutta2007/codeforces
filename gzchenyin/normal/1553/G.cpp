#include<cstdio>
#include<set>
#include<vector>
using namespace std;
long long P[1000005],cnt,Rev[1000005];
bool NotP[1000005];
void init()
{
    for(int i=2;i<=1000000;i++)
    {
        if(!NotP[i]) 
        {
            P[++cnt]=i;
            Rev[i]=cnt;
        }
        for(int j=1;j<=cnt && i*P[j]<=1000000;j++)
        {
            NotP[i*P[j]]=true;
        }
    }
}
int n,q,a[150005],F[300005];
int G(int x)
{
    return F[x]==x ? x : F[x]=G(F[x]);
}
void Merge(int x,int y)
{
    x=G(x); y=G(y);
    if(x!=y) F[x]=y;
}
set<int> st[300005];
int main()
{
    for(int i=1;i<=300000;i++) F[i]=i;
    scanf("%d%d",&n,&q);
    init();
//    printf("%d\n",cnt);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        int Now=a[i];
        for(int j=1;P[j]<=1000;j++)
        {
            if(Now%P[j]==0)
            {
                while(Now%P[j]==0) Now/=P[j];
                Merge(i,n+j);
            } 
        }
        if(Now!=1) Merge(i,n+Rev[Now]);
    }
    for(int i=1;i<=n;i++)
    {
        int Now=a[i]+1;
        vector<int> Vec;
        Vec.push_back(i);
        for(int j=1;P[j]<=1000;j++)
        {
            if(Now%P[j]==0)
            {
                while(Now%P[j]==0) Now/=P[j];
                Vec.push_back(n+j);
            } 
        }
        if(Now!=1) Vec.push_back(n+Rev[Now]);
        for(int x=0;x<=Vec.size();x++)
        {
            for(int y=x+1;y<Vec.size();y++)
            {
                st[G(Vec[x])].insert(G(Vec[y]));
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(G(x)==G(y)) printf("0\n");
        else if(st[G(x)].find(G(y))!=st[G(x)].end() || st[G(y)].find(G(x))!=st[G(y)].end()) printf("1\n");
        else printf("2\n");
    }
}