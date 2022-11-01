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
const int N=4E4+10;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

const int p=1E9+7;
int a[N];
bool check(int x)
{
    string u=to_string(x),v=u;
    reverse(v.begin(),v.end());
    return u==v;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    a[0]=1;
    for(int i=1;i<N;++i)if(check(i))
    {
        for(int j=i;j<N;++j)
        {
            a[j]=(a[j]+a[j-i])%p;
        }
    }
    for(int n=read();n--;cout<<a[read()]<<'\n');
}