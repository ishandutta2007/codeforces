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
const int N=1E6+10;
const int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

int pre[N],f[N];
bool b[N];
int _pre(int i){return i<0?0:pre[i];}
int _f(int i){return i<0?0:f[i];}
void solve()
{
    int n=read(),m=read(),s=n*m;
    for(int i=0;i<m;++i)b[i]=0;
    for(int i=0,ans=0;i<s;++i)
    {
        pre[i]=_pre(i-1);
        if(read<char>()&1)
        {
            ++pre[i];
            if(!b[i%m])ans+=b[i%m]=1;
        }
        f[i]=_f(i-m)+!!(pre[i]-_pre(i-m));
        cout<<ans+f[i]<<' ';
    }
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}