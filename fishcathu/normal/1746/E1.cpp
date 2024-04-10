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
constexpr int N=2E5+10;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

vector<int>a,b,c,d;
bool ask(int x,int y)
{
    cout<<"? "<<x+y<<' ';
    for(int i=0;i<x;++i)cout<<a[i]<<' ';
    for(int i=0;i<y;++i)cout<<b[i]<<' ';
    cout<<endl;
    return read<string>()[0]=='Y';
}
bool ask(int x)
{
    cout<<"! "<<x<<endl;
    return read<string>()[1]==')';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    a.resize(read());
    iota(a.begin(),a.end(),1);
    while(a.size()+b.size()>2)
    {
        c.clear();
        d.clear();
        int x=a.size()+b.size()%2+1>>1,y=b.size()>>1;
        if(ask(x,y))
        {
            c.insert(c.end(),a.begin(),a.begin()+x);
            c.insert(c.end(),b.begin(),b.begin()+y);
            d.insert(d.end(),a.begin()+x,a.end());
        }
        else
        {
            c.insert(c.end(),a.begin()+x,a.end());
            c.insert(c.end(),b.begin()+y,b.end());
            d.insert(d.end(),a.begin(),a.begin()+x);
        }
        a=c;
        b=d;
    }
    a.insert(a.end(),b.begin(),b.end());
    if(!ask(a[0]))ask(a[1]);
}