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
 
#define mod 1000000007
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

#define maxn 1000005
#define inf 0x3f3f3f3f

int n,a[maxn],t[maxn],m;
modint tr[maxn];
inline void add(int x,modint y){
	if(x>n)return;
	if(x<=0){
		puts("WA");
		exit(0);
	}
	for(;x<=n;x+=x&-x)tr[x]+=y;
}
inline modint ask(int x){
	modint res=0;
	for(;x;x^=x&-x)res+=tr[x];
	return res;
}

int stk[maxn],top;
int go[maxn];
vi vec[maxn]; 
modint fl[maxn],fr[maxn],f[maxn];
void work()
{
	n=read();
	m=0;
	For(i,1,n)a[i]=read(),t[++m]=a[i],vec[i].clear();
	sort(t+1,t+m+1);
	m=unique(t+1,t+m+1)-t-1;
	For(i,1,n)a[i]=lower_bound(t+1,t+m+1,a[i])-t;
	modint res=0;
	
	top=0;
	Rep(i,n,1){
		if(!top || a[i]>=a[stk[top]]){
			stk[++top]=i;
			go[i]=-1;
			continue;
		}
		int l=1,r=top,p=top;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]<a[stk[mid]]) p=mid,r=mid-1;
			else l=mid+1;
		}
		go[i]=stk[p];
		vec[go[i]].pb(i);
	}
	
	For(i,0,n)tr[i]=0;
	For(i,1,n){
		fl[i]=ask(a[i]-1)+1;
		add(a[i],fl[i]);
	}
	For(i,0,n)tr[i]=0;
	Rep(i,n,1){
		fr[i]=ask(n-(a[i]+1)+1)+1;
		add(n-a[i]+1,fr[i]);
	}
	
	For(i,0,n)tr[i]=0;
	For(i,1,top){
		int u=stk[i];
		f[u]=fr[u];
	//	cout<<"solve "<<u<<endl;
		// sub : 
		for(auto v:vec[u]) {
			modint sub = ask(n-(a[v]+1)+1)+1;
		//	cout<<"v: "<<v<<" "<<f[v].x<<" "<<sub.x<<endl;
			f[v] = sub;
			add(n-a[v]+1,sub);
		}
		for(auto v:vec[u]) add(n-a[v]+1,-f[v]);
	}
	
	For(i,1,n) res+=(fr[i]-f[i])*fl[i];
	cout<<res.x<<endl;
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}