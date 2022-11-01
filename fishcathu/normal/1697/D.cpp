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
constexpr int N=1010;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

char a[N];
int las[123],q[27],s;
char ask(int x){cout<<"? 1 "<<x<<endl;return read<char>();}
int ask(int x,int y){cout<<"? 2 "<<x<<' '<<y<<endl;return read();}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int i=1,m=0;i<=n;++i)
    {
        if(cmax(m,ask(1,i)))a[i]=ask(i);
        else
        {
            s=0;
            for(char j='a';j<='z';++j)if(las[j])q[++s]=las[j];
            sort(q+1,q+1+s);
            int l=1,r=s;
            while(l^r)
            {
                int mid=l+r+1>>1;
                ask(q[mid],i)^s-mid+1?r=mid-1:l=mid;
            }
            a[i]=a[q[l]];
        }
        las[a[i]]=i;
    }
    cout<<"! "<<a+1<<endl;
}