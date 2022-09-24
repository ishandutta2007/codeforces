#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL n=131072;
LL ST1[n*2+10],ST2[n*2+10];
inline void SI1(LL X,LL dif)
{
    for(X+=n;X>0;X>>=1)
        ST1[X]=min(ST1[X],dif);
    return;
}
inline void SI2(LL X,LL dif)
{
    for(X+=n;X>0;X>>=1)
        ST2[X]=max(ST2[X],dif);
    return;
}
inline LL Sm(LL L,LL R)
{
    LL ans=INF;
    L+=n;
    R+=n;
    while(L<=R)
    {
        ans=min(ans,min(ST1[L],ST1[R]));
        L=L+1>>1;
        R=R-1>>1;
    }
    return ans;
}
inline LL SM(LL L,LL R)
{
    LL ans=0;
    L+=n;
    R+=n;
    while(L<=R)
    {
        ans=max(ans,max(ST2[L],ST2[R]));
        L=L+1>>1;
        R=R-1>>1;
    }
    return ans;
}
vector<LL>adj[n];
LL cnt;
LL out[n],PR[n];
LL dep[n];
void dfs(const LL&X,LL d)
{
    dep[X]=d;
    for(LL i=0;i<adj[X].size();i++)
        dfs(adj[X][i],d+1);
    PR[out[X]=cnt++]=X;
    return;
}
LL spa[n][20];
inline LL LCA(LL L,LL R)
{
    if(dep[L]<dep[R])
        swap(L,R);
    LL i;
    for(i=18;i-->0;)
        if(dep[L]-dep[R]>>i&1)
            L=spa[L][i];
    if(L==R)
        return L;
    for(i=18;i-->0;)
    {
        if(spa[L][i]!=spa[R][i])
        {
            L=spa[L][i];
            R=spa[R][i];
        }
    }
    return spa[L][0];
}
LL N,Q;
LL i,j;
LL L,R;
LL P[n];
LL ans1,ans2,ans3,ans4;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>Q;
    P[0]=-1;
    for(i=1;i<N;i++)
    {
        cin>>P[i];
        adj[--P[i]].push_back(i);
    }
    dfs(0,0);
    for(i=0;i<N;i++)
        spa[i][0]=P[i];
    for(i=1;i<18;i++)
        for(j=0;j<N;j++)
            spa[j][i]=spa[j][i-1]==-1?-1:spa[spa[j][i-1]][i-1];
    fill(ST1,ST1+(n<<1),INF);
    for(i=0;i<N;i++)
    {
        SI1(i,out[i]);
        SI2(i,out[i]);
    }
    while(Q-->0)
    {
        cin>>L>>R;
        ans1=PR[Sm(--L,--R)];
        ans2=dep[LCA(PR[min(Sm(L,ans1-1),Sm(ans1+1,R))],PR[max(SM(L,ans1-1),SM(ans1+1,R))])];
        ans3=PR[SM(L,R)];
        ans4=dep[LCA(PR[min(Sm(L,ans3-1),Sm(ans3+1,R))],PR[max(SM(L,ans3-1),SM(ans3+1,R))])];
        if(ans2>ans4)
            cout<<ans1+1<<' '<<ans2<<'\n';
        else
            cout<<ans3+1<<' '<<ans4<<'\n';
    }
    cout<<endl;
    return 0;
}