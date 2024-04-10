#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
//#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define mod 998244353
struct modint{
    int x;
    modint(int o=0){x=o;}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
	template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
	friend bool operator ==(modint a,int b){return a.x==b;}
	friend bool operator !=(modint a,int b){return a.x!=b;}
	bool operator ! () {return !x;}
	modint operator - () {return x?mod-x:0;}
};

#define maxn 200005
#define inf 0x3f3f3f3f

void work()
{
	
}
vector<pii>v[2];
signed main()
{
	int n;
	cin>>n;
	For(i,1,n)For(j,1,n) v[(i+j)%2].pb(mkp(i,j));
	For(i,1,n*n)
	{
		int x;cin>>x;
		if(x!=1){
			if(v[0].size()){
				cout<<1<<" "<<v[0].back().fi<<' '<<v[0].back().se<<endl;
				v[0].pop_back(); 
			}else{
				cout<<(x==2?3:2)<<' '<<v[1].back().fi<<' '<<v[1].back().se<<endl;
				v[1].pop_back(); 
			}
		}
		else if(x!=2){
			if(v[1].size()){
				cout<<2<<" "<<v[1].back().fi<<' '<<v[1].back().se<<endl;
				v[1].pop_back(); 
			}else{
				cout<<(x==1?3:1)<<' '<<v[0].back().fi<<' '<<v[0].back().se<<endl;
				v[0].pop_back(); 
			}
		}
	}
	return 0;
}