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
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}
const int N=2E5+10;
const int inf=1<<30;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    int a=read(),b=read(),c=read(),d=read(),k;
    if(c==d+1)k=0;
    else if(d==c+1)--a,--b,k=3;
    else if(c^d)return cout<<"-1\n",0;
    else if(a>c)--a,k=2;
    else --b,k=1;
    if(a<c||b<c)return cout<<"-1\n",0;
    if(k&1)cout<<'7';
    for(int i=a-c;i--;cout<<'4');
    for(int i=c;i--;cout<<"47");
    for(int i=b-c;i--;cout<<'7');
    if(k&2)cout<<'4';
    cout<<'\n';
}