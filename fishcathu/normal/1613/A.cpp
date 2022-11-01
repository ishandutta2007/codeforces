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
const int inf=1<<30;
template<typename T>T min(T x){return x;}
template<typename T>T max(T x){return x;}
template<typename T,typename...Args>auto min(T l,Args...args){auto r=min(args...);return l<r?l:r;}
template<typename T,typename...Args>auto max(T l,Args...args){auto r=max(args...);return l>r?l:r;}
template<typename T>bool cmin(T &l,T r){return l>r?l=r,1:0;}
template<typename T>bool cmax(T &l,T r){return l<r?l=r,1:0;}
template<typename T=int>T read()
{
    T a=0;int b=1;char c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void init(string &a,int &n)
{
    cin>>a;
    n=a.size()+read();
    while(a.back()=='0')a.pop_back();
}
int solve()
{
    string a,b;
    int n,m;
    init(a,n);
    init(b,m);
    if(n<m)return -1;
    if(n>m)return 1;
    if(a<b)return -1;
    if(a>b)return 1;
    return 0;
}
int main()
{
    for(int T=read();T--;)
    {
        int x=solve();
        if(x<0)puts("<");
        else if(!x)puts("=");
        else puts(">");
    }
}