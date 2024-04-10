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
#define mkp make_pair
#define pb push_back
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 500005
#define inf 0x3f3f3f3f

int n,nd;
int now,res=inf;
int b[233][233],a[233][233];
vector<pii>o;
bool fl;
int qaq[6]={0,1,1,2,3,3};
bool chk(){
	For(i,1,n)For(j,1,n)if(!a[i][j])return 0;
	For(i,1,n)For(j,1,n)if(b[i][j])o.pb(mkp(i,j));
	 return 1;
} 
void dfs(int x,int y){
	if(now>res||fl)return;
//	cout<<"dfs "<<x<<" "<<y<<endl;
	if(x==n+1){
//		For(i,1,n)For(j,1,n)cout<<a[i][j]<<" \n"[j==n];
		if(chk())
			return fl=1,void();
		return;
	}
	
	if(a[x][y]){
		if(y==n)dfs(x+1,1);
		else dfs(x,y+1);return;
	}
	
	For(i,1,n)
		For(j,1,n){
			if(i==x||j==y||i-j==x-y)
				++a[i][j];
		}
	b[x][y]=1,++now;
	if(y==n)dfs(x+1,1);
	else dfs(x,y+1);
	b[x][y]=0,--now;
	For(i,1,n)
		For(j,1,n){
			if(i==x||j==y||i-j==x-y)
				--a[i][j];
		}
	
	if(y==n)dfs(x+1,1);
	else dfs(x,y+1);
}

signed main()
{
	n=read();
	if(n%3!=0){
		int y=1,x=1;
		int c=n/3;
		cout<<c+1+c<<endl;
		For(i,1,c+1){
			cout<<x<<" "<<y<<endl;
			x+=1,y+=2;
		}
		y=2;
		For(i,1,c){
			cout<<x<<" "<<y<<endl;
			x+=1,y+=2;
		}
	}else{
		int y=1,x=1;
		int c=n/3;
		cout<<c+c<<endl;
		For(i,1,c){
			cout<<x<<" "<<y<<endl;
			x+=1,y+=2;
		}
		y=2;
		For(i,1,c){
			cout<<x<<" "<<y<<endl;
			x+=1,y+=2;
		}
	}
    return 0;
}
/*
cnt+=4 ,n+=6
1 2 3 4 5 6 7 8 9
1 1 2 3 3 4 5 5 6
*/