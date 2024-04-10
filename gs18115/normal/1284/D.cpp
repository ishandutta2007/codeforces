#include<iostream>
#include<vector>
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
void no()
{
    cout<<"NO"<<endl;
    exit(0);
}
void yes()
{
    cout<<"YES"<<endl;
    exit(0);
}
struct seg
{
    ll t[800010];
    void si(int n,int s,int e,int x,ll p)
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
}st1,st2;
vector<pl>ex[200010];
int ec;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<pl,pl> >v(n);
    vector<ll>t1,t2;
    for(auto&t:v)
        cin>>t.fi.fi>>t.fi.se>>t.se.fi>>t.se.se,t1.eb(t.fi.fi),t1.eb(t.fi.se),t2.eb(t.se.fi),t2.eb(t.se.se);
    sort(all(v));
    sort(all(t1));
    sort(all(t2));
    t1.erase(unique(all(t1)),t1.end());
    t2.erase(unique(all(t2)),t2.end());
    ll ss=t2.size();
    for(auto&t:v)
        t.fi.fi=lower_bound(all(t1),t.fi.fi)-t1.begin(),
        t.fi.se=lower_bound(all(t1),t.fi.se)-t1.begin(),
        t.se.fi=lower_bound(all(t2),t.se.fi)-t2.begin(),
        t.se.se=lower_bound(all(t2),t.se.se)-t2.begin();
    for(auto&t:v)
        ex[t.fi.se].eb(t.se);
    for(auto&t:v)
    {
        for(;ec<t.fi.fi;ec++)
            for(auto&tt:ex[ec])
                st1.si(1,0,ss,tt.se,-1),st2.si(1,0,ss,tt.fi,-1);
        st1.si(1,0,ss,t.se.se,1);
        st2.si(1,0,ss,t.se.fi,1);
        if(st1.ss(1,0,ss,0,t.se.fi-1)>0)
            no();
        if(st2.ss(1,0,ss,t.se.se+1,ss)>0)
            no();
    }
    for(;ec<=t1.size();ec++)
        for(auto&tt:ex[ec])
            st1.si(1,0,ss,tt.se,-1),st2.si(1,0,ss,tt.fi,-1);
    ss=t1.size();
    for(int i=0;i<=ss;i++)
        ex[i].clear();
    ec=0;
    for(auto&t:v)
        swap(t.fi,t.se),ex[t.fi.se].eb(t.se);
    sort(all(v));
    for(auto&t:v)
    {
        for(;ec<t.fi.fi;ec++)
            for(auto&tt:ex[ec])
                st1.si(1,0,ss,tt.se,-1),st2.si(1,0,ss,tt.fi,-1);
        st1.si(1,0,ss,t.se.se,1);
        st2.si(1,0,ss,t.se.fi,1);
        if(st1.ss(1,0,ss,0,t.se.fi-1)>0)
            no();
        if(st2.ss(1,0,ss,t.se.se+1,ss)>0)
            no();
    }
    yes();
    return 0;
}