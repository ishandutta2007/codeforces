#include<iostream>
#include<vector>
#include<set>
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
    int st[400010],lz[400010],mx[400010];
    void init(int n,int s,int e,vector<int>&v)
    {
        lz[n]=0;
        if(s==e)
        {
            st[n]=mx[n]=v[s-1];
            return;
        }
        int m=s+(e-s)/2;
        init(n*2,s,m,v);
        init(n*2+1,m+1,e,v);
        st[n]=min(st[n*2],st[n*2+1]);
        mx[n]=max(mx[n*2],mx[n*2+1]);
        return;
    }
    inline void put(int n,int p)
    {
        st[n]+=p;
        mx[n]+=p;
        lz[n]+=p;
        return;
    }
    inline void prop(int n)
    {
        if(lz[n]==0)
            return;
        put(n*2,lz[n]);
        put(n*2+1,lz[n]);
        lz[n]=0;
        return;
    }
    void rm(int n,int s,int e,int p)
    {
        if(s==e&&st[n]==p)
        {
            st[n]=inf;
            mx[n]=-inf;
            return;
        }
        prop(n);
        int m=s+(e-s)/2;
        if(p>mx[n*2])
            rm(n*2+1,m+1,e,p);
        else
            rm(n*2,s,m,p);
        st[n]=min(st[n*2],st[n*2+1]);
        mx[n]=max(mx[n*2],mx[n*2+1]);
        return;
    }
    void upd(int n,int s,int e,int E,int v)
    {
        if(mx[n]<=E)
            return put(n,v);
        if(s==e)
            return;
        prop(n);
        int m=s+(e-s)/2;
        if(mx[n*2]>E)
            upd(n*2,s,m,E,v);
        else
            put(n*2,v),upd(n*2+1,m+1,e,E,v);
        st[n]=min(st[n*2],st[n*2+1]);
        mx[n]=max(mx[n*2],mx[n*2+1]);
        return;
    }
}st[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        ll m=INF;
        ll cc=0;
        vector<vector<int> >vv(26);
        for(int i=0;i<n;i++)
            vv[s[i]-'a'].eb(i+1);
        vector<int>sz(26);
        for(int i=0;i<26;i++)
        {
            vv[i].eb(n+1);
            sz[i]=vv[i].size();
            st[i].init(1,1,sz[i],vv[i]);
        }
        for(int i=0;i++<n;)
        {
            int tc=t[i-1]-'a';
            for(int j=0;j<tc;j++)
            {
                int cp=st[j].st[1];
                if(cp<=n)
                    m=min(m,cc+cp-i);
            }
            int cp=st[tc].st[1];
            if(cp>n)
                break;
            cc+=cp-i;
            st[tc].rm(1,1,sz[tc],cp);
            for(int j=0;j<26;j++)
                st[j].upd(1,1,sz[j],cp,1);
        }
        if(m==INF)
            m=-1;
        cout<<m<<'\n';
    }
    return 0;
}