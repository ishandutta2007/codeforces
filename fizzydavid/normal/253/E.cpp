#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll LINF=1ll<<61;
int n,t[50011],s[50011],p[50011];
vector<int>pi,v;
vector<pair<int,int> >q;
ll T,ans[50011],ID,lft[50011];
priority_queue<pair<int,int> >pq;
ll solve()
{
    for(int i=1;i<=n;i++)lft[i]=s[i];
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(j<n&&q[j].FF==q[i].FF)
        {
            pq.push(MP(p[q[j].SS],q[j].SS));
            j++;
        }
        ll nxt,ti=q[i].FF;
        if(i==n-1)nxt=LINF;else nxt=q[i+1].FF;
        while(!pq.empty())
        {
            int x=pq.top().SS;
            ll cost=min(lft[x],nxt-ti);
            lft[x]-=cost;
            ti+=cost;
            if(lft[x]==0)pq.pop(),ans[x]=ti;else break;
        }
    }
    return ans[ID];
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i]>>s[i]>>p[i];
        pi.PB(p[i]);
        if(p[i]==-1)ID=i;
    }
    pi.PB(0),pi.PB(1000000001);
    sort(pi.begin(),pi.end());
    for(int i=1;i<pi.size();i++)if(pi[i-1]+1<pi[i])v.PB(pi[i-1]+pi[i]>>1);
    cin>>T;
    for(int i=1;i<=n;i++)q.PB(MP(t[i],i));
    sort(q.begin(),q.end());
    int l=0,r=int(v.size())-1;
    while(l<=r)
    {
        int m=l+r>>1;
        p[ID]=v[m];
        if(solve()>T)l=m+1;else r=m-1;
    }
    p[ID]=v[l];
    solve();
    cout<<v[l]<<endl;
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}