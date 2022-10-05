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

struct frac{
	int x,y;
	frac(){}
	frac(int xx,int yy=1ll):x(xx),y(yy){
		int g=__gcd(abs(x),abs(y));
		if(y<0)g=-g;
		x/=g,y/=g;
	}
	friend frac operator +(frac a,frac b){return frac(a.x*b.y+a.y*b.x,a.y*b.y);}
	friend frac operator -(frac a,frac b){return frac(a.x*b.y-a.y*b.x,a.y*b.y);}
	friend frac operator *(frac a,frac b){return frac(a.x*b.x,a.y*b.y);}
	friend frac operator /(frac a,frac b){return a*frac(b.y,b.x);}
	friend bool operator <(frac a,frac b){return a.x*b.y<b.x*a.y;}
	friend bool operator >(frac a,frac b){return a.x*b.y>b.x*a.y;}
	friend bool operator <=(frac a,frac b){return !(a>b);}
	friend bool operator >=(frac a,frac b){return !(a<b);}
	friend bool operator ==(frac a,frac b){return a.x*b.y==b.x*a.y;}
	friend bool operator !=(frac a,frac b){return !(a==b);}
	frac operator - () {return frac(0)-x;}
};

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 400005
#define inf 0x3f3f3f3f

int n,A,B,C;
char s[maxn];
int a[maxn],b[maxn],m; 
int cnt[2];
int t[maxn],k;

void work()
{
	n=read();m=0;
	A=read(),B=read(),C=read();
	cnt[0]=cnt[1]=0; 
	cin>>s+1;
	For(l,1,n){
		int r=l;
		while(r<n&&s[r+1]==s[l])++r;
		a[++m]=(r-l+1);
		b[m]=(s[l]&1);
		cnt[b[m]]+=(a[m]-1);
		l=r;
	}
	int res=A*min(cnt[0],cnt[1]+1);
	res+=B*min(cnt[1],cnt[0]+1);
//	cout<<"res: "<<res<<endl;
	if(C>=B){
		cout<<res<<endl;
		return;
	}
	k=0;
	int kk=0;
	For(i,1,m)
		if(!b[i]){
			if(i==1 || i==m) kk++;
			else t[++k]=a[i]-1;
		}
	sort(t+1,t+k+1);
	if(cnt[0]>=cnt[1]){
		int res2=cnt[1]*(A+B);
		int xiao=cnt[1];
		For(i,1,k){
			xiao -= t[i];
			if(xiao>=0) res2+=B-C;
		}
		if(cnt[0]>cnt[1]) res2+=A;
		cout<<max(res,res2)<<endl;
	}else{
		// 1 0 1 0 1 0 1 2 
		int res2=cnt[0]*A+(cnt[0]+1)*B;
		cnt[1]-=cnt[0]+1;
		For(i,1,k) res2+=B-C;
		int d=min(cnt[1],kk);
		res2 += (B-C) * d;
		cout<<max(res,res2)<<endl; 
	}
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}