#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define min amin
#define max amax
#define pb push_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int N=2E5+10;
const int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

int a[N],tot[N],cnt,val;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int n=read(),m=read();
    ll ans=0;
    for(int i=1;i<=n;++i)ans+=a[i]=read();
    while(m--)
    {
        if(read()&1)
        {
            int i=read(),x=read();
            if(tot[i]<cnt)a[i]=val,tot[i]=cnt;
            ans+=x-a[i];
            a[i]=x;
        }
        else
        {
            ++cnt;
            cin>>val;
            ans=1LL*n*val;
        }
        cout<<ans<<'\n';
    }
}