#include<iostream>
#include<vector>
#include<queue>
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
    void upd(int n,int s,int e,int x,int p)
    {
        if(s==e)
        {
            st[n]=p;
            return;
        }
        int m=s+(e-s)/2;
        if(x<=m)
            upd(n*2,s,m,x,p);
        else
            upd(n*2+1,m+1,e,x,p);
        st[n]=min(st[n*2],st[n*2+1]);
        return;
    }
    int qry(int n,int s,int e,int S,int E)
    {
        if(s>E||S>e)
            return inf;
        if(S<=s&&e<=E)
            return st[n];
        int m=s+(e-s)/2;
        return min(qry(n*2,s,m,S,E),qry(n*2+1,m+1,e,S,E));
    }
}st1,st2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    cin>>tc;
    while(tc-->0)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        vector<int>mxstak;
        vector<int>mnstak;
        vector<int>dp(n);
        dp[0]=0;
        mxstak.eb(0);
        mnstak.eb(0);
        st1.init(1,0,n);
        st1.upd(1,0,n,0,0);
        st2.init(1,0,n);
        st2.upd(1,0,n,0,0);
        for(int i=1;i<n;i++)
        {
            int mxp=-1,mnp=-1;
            while(!mxstak.empty()&&v[mxstak.back()]<v[i])
                st1.upd(1,0,n,mxstak.back(),inf),mxstak.pop_back();
            while(!mnstak.empty()&&v[mnstak.back()]>v[i])
                st2.upd(1,0,n,mnstak.back(),inf),mnstak.pop_back();
            if(v[i]<v[i-1]) //mxstak
            {
                int p=mnstak.empty()?0:mnstak.back()+1;
                dp[i]=st1.qry(1,0,n,p,i-1)+1;
            }
            else //mnstak
            {
                int p=mxstak.empty()?0:mxstak.back()+1;
                dp[i]=st2.qry(1,0,n,p,i-1)+1;
            }
            mxstak.eb(i);
            mnstak.eb(i);
            st1.upd(1,0,n,i,dp[i]);
            st2.upd(1,0,n,i,dp[i]);
        }
        cout<<dp[n-1]<<'\n';
        //cout<<endl;
    }
    return 0;
}