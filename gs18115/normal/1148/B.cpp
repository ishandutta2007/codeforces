#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
/*struct fenwick
{
    LL dat[200010];
    fenwick()
    {
        fill(dat,dat+200010,INF);
    }
    void FI(LL x,LL p)
    {
        for(x++;x<200010;x+=x&-x)
            dat[x]=min(dat[x],p);
        return;
    }
    LL FM(LL x)
    {
        LL ans=INF;
        for(x++;x>0;x=x&x-1)
            ans=min(ans,dat[x]);
        return ans;
    }
}FT;*/
LL N,M,ta,tb,K;
LL i;
LL A[200010],B[400010];
LL ans;
vector<LL>V;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M>>ta>>tb>>K;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<M;i++)
        cin>>B[i];
    for(i=0;i<=M;i++)
        B[M+i]=INF;
    if(K>=N||K>=M)
        return cout<<-1<<endl,0;
    for(i=0;i<=K;i++)
        ans=max(ans,B[lower_bound(B,B+M,A[i]+ta)-B+K-i]);
    if(ans>INF>>1)
        return cout<<-1<<endl,0;
    cout<<ans+tb<<endl;
    return 0;
}