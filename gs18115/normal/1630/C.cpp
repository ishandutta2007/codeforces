#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
struct seg
{
    int st[1000010];
    void init(int n,int s,int e)
    {
        st[n]=inf;
        if(s==e)
            return;
        int m=s+(e-s)/2;
        init(n*2,s,m);
        init(n*2+1,m+1,e);
        return;
    }
    void put(int n,int s,int e,int S,int E,int p)
    {
        if(s>E||S>e)
            return;
        if(S<=s&&e<=E)
        {
            st[n]=min(st[n],p);
            return;
        }
        int m=s+(e-s)/2;
        put(n*2,s,m,S,E,p);
        put(n*2+1,m+1,e,S,E,p);
        return;
    }
    int get(int n,int s,int e,int x)
    {
        if(s==e)
            return st[n];
        int m=s+(e-s)/2;
        int r;
        if(x>m)
            r=get(n*2+1,m+1,e,x);
        else
            r=get(n*2,s,m,x);
        return min(st[n],r);
    }
}st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>ls(n+1,0);
    for(int&t:v)
        cin>>t;
    for(int i=0;i<n;i++)
        ls[v[i]]=i;
    vector<int>dp(n+1,0);
    st.init(1,0,n);
    for(int i=0;i<n;i++)
    {
        dp[i+1]=min(dp[i]+1,st.get(1,0,n,i)+1);
        st.put(1,0,n,i,ls[v[i]],dp[i+1]);
    }
    cout<<n-dp[n]<<endl;
    return 0;
}