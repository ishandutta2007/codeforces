#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
struct seg
{
    ll t[800010];
    void si(int n,int s,int e,int x,int p)
    {
        t[n]+=p;
        if(s==e)
            return;
        int m=s+e>>1;
        if(x>m)
            si(n*2+1,m+1,e,x,p);
        else
            si(n*2,s,m,x,p);
        return;
    }
    ll ss(int n,int s,int e,int S,int E)
    {
        if(s>E||S>e)
            return 0;
        if(S<=s&&e<=E)
            return t[n];
        int m=s+e>>1;
        return ss(n*2,s,m,S,E)+ss(n*2+1,m+1,e,S,E);
    }
}st;
priority_queue<int,vector<int>,less<int> >pq1;
priority_queue<int,vector<int>,greater<int> >pq2;
int n,i;
ll ans,inv;
int v[200010],p[200010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(i=0;i++<n;)
        cin>>p[i],v[p[i]]=i;
    st.si(1,1,n,v[1],1);
    pq1.ep(v[1]);
    cout<<0;
    for(i=1;i++<n;)
    {
        inv+=st.ss(1,1,n,v[i],n);
        st.si(1,1,n,v[i],1);
        if(pq1.top()>v[i])
            ans+=pq1.top()-v[i]-(ll)pq1.size(),pq1.ep(v[i]);
        else
            ans+=v[i]-pq1.top()-(ll)pq2.size()-1,pq2.ep(v[i]);
        while(pq1.size()>pq2.size()+1)
        {
            pq2.ep(pq1.top());
            pq1.pop();
            ll sft=pq2.top()-pq1.top();
            ans+=(sft-1)*((ll)pq2.size()-(ll)pq1.size());
        }
        while(pq1.size()<pq2.size())
        {
            ll sft=(ll)pq2.top()-(ll)pq1.top();
            ans-=pq1.size();
            ans+=sft*(ll)pq1.size();
            ans-=sft*(ll)pq2.size();
            ans+=pq2.size();
            pq1.ep(pq2.top());
            pq2.pop();
        }
        cout<<' '<<ans+inv;
    }
    cout<<endl;
    return 0;
}