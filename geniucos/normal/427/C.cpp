#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int mini,Nr,P,nr,poz,n,m,i,x1,y11,ap[100009],Q[100009],cst[100009];
long long sol;
queue < int > cc;
vector < int > a,v[100009],h[100009];
vector < vector < int > > ras;
vector < int > ::iterator it;
void dfs(int nod)
{
    vector < int > ::iterator it;
    ap[nod]=1;
    for(it=v[nod].begin();it!=v[nod].end();it++)
        if(ap[*it]==0) dfs(*it);
    nr++;
    Q[nr]=nod;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&cst[i]);
scanf("%d",&m);
for(i=1;i<=m;i++)
{
    scanf("%d",&x1);
    scanf("%d",&y11);
    v[x1].push_back(y11);
    h[y11].push_back(x1);
}
for(i=1;i<=n;i++)
    if(ap[i]==0) dfs(i);
for(i=1;i<=n;i++)
    ap[i]=0;
poz=nr;
P=1;
while(1)
{
    while(ap[Q[poz]]==1) poz--;
    if(poz==0) break;
    cc.push(Q[poz]);
    a.clear();
    ap[Q[poz]]=1;
    a.push_back(Q[poz]);
    while(!cc.empty())
    {
        x1=cc.front();
        cc.pop();
        for(it=h[x1].begin();it!=h[x1].end();it++)
            if(ap[*it]==0)
            {
                ap[*it]=1;
                a.push_back(*it);
                cc.push(*it);
            }
    }
    /////a e componenta tare conexa
    mini=1000000001;
    for(it=a.begin();it!=a.end();it++)
    {
        if(cst[*it]<mini) mini=cst[*it],Nr=1;
        else
        if(cst[*it]==mini) Nr++;
    }
    sol+=mini;
    P=(1LL*P*Nr)%1000000007;
}
printf("%I64d %d\n",sol,P);
return 0;
}