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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    vector<pii>a;
    for(int n=read(),u=1,v=1;n--;)
    {
        for(char x:read<string>())
        {
            int t=(u-v+p)%p;
            vector<pii>b;
            for(auto [y,k]:a)
            {
                int z=x-47;
                while(y&-y&z<<1)y&=y-1,z<<=2;
                if(!y)t=(t-k+p)%p;
                else if((y&-y)<=z)continue;
                b.pb({y|z,k});
            }
            if(x&1)b.pb({2,v});
            swap(a,b);
            (u+=v=t)%=p;
        }
        cout<<v<<'\n';
    }
}