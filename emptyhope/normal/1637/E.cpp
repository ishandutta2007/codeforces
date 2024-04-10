#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

// modint
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
	bool operator <(const modint&b)const{return x<b.x;}
};
inline modint qpow(modint x,int y){return x^y;}

vector<modint> fac,ifac,iv;
inline void initC(int n)
{
	if(iv.empty())fac=ifac=iv=vector<modint>(2,1);
	int m=iv.size(); ++n;
	if(m>=n)return;
	iv.resize(n),fac.resize(n),ifac.resize(n);
	For(i,m,n-1){
		iv[i]=iv[mod%i]*(mod-mod/i);
		fac[i]=fac[i-1]*i,ifac[i]=ifac[i-1]*iv[i];
	}
}
inline modint C(int n,int m){
	if(m<0||n<m)return 0;
	return initC(n),fac[n]*ifac[m]*ifac[n-m];
}
inline modint sign(int n){return (n&1)?(mod-1):(1);}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 300005
#define inf 0x3f3f3f3f

int n,m,a[maxn],c[maxn],val[maxn];
map<int,int>mp; int cnt;
inline int ID(int x){
	if(!mp.count(x))return mp[x]=++cnt,val[cnt]=x,cnt;
	return mp[x];
}

map< pii , int >mp2;
int o[maxn],len;
vector<int>cc[maxn];
	
void work()
{
	n=read(),m=read(),mp.clear(),cnt=0;
	For(i,1,n)c[i]=0,cc[i].clear();
	For(i,1,n){
		a[i]=read(),a[i]=ID(a[i]);
		c[a[i]]++;
	}
	
	For(i,1,cnt) cc[c[i]].pb(val[i]);
	len=0;
	For(i,1,n) if(cc[i].size()) sort(cc[i].begin(),cc[i].end(),greater<int>()),o[++len]=i;
	
	mp2.clear();
	For(i,1,m){
		int x=read(),y=read();
		mp2[mkp(x,y)]=mp2[mkp(y,x)]=1;
	}
	
	int res=0;
	For(_,1,len){
		int i=o[_];
		int szi=cc[i].size();
		For(__,_+1,len){
			int j=o[__];
			int szj=cc[j].size();
			For(x,0,szi-1){
				bool ok=0;
				For(y,0,szj-1){
					if(!mp2.count(mkp(cc[i][x],cc[j][y]))){
						if(y==0) ok=1;
		//				cout<<"i,j "<<cc[i][x]<<" "<<cc[j][y]<<" "<<i<<" "<<j<<endl;
						res=max(res,(cc[i][x]+cc[j][y])*(i+j));
						break;
					}
				}
				if(ok)break;
			}
		}
		For(x,0,szi-1){
			bool ok=0;
			For(y,x+1,szi-1){
				if(!mp2.count(mkp(cc[i][x],cc[i][y]))){
					if(y==x+1)ok=1;
					res=max(res,(cc[i][x]+cc[i][y])*(i+i));
					break;
				}
			}
			if(ok)break;
		}
	}
	cout<<res<<endl;
}

signed main()
{
	int T=read();
	while(T--)work();
    return 0;
}