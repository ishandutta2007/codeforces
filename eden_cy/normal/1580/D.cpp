#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])

typedef double db;
typedef long long ll;

namespace Eddd {
	inline char sc() {
		return getchar();
		static const int LEN=100000;
		static char Buf[LEN],*OP=Buf,*ED=Buf;
		if(OP==ED) ED=(OP=Buf)+fread(Buf,1,LEN,stdin);
		return *OP++;
	}
	template<class T> void rd(T &x) {
		static int c,f;x=f=0;
		while(c=sc(),c<48) if(c=='-') f=1;
		do x=(x<<3)+(x<<1)+(c^48);
		while(c=sc(),c>47);if(f) x=-x;
	}
	template<class T> void pt(T x) {
		if(x<0) putchar('-'),x=-x;
		else if(!x) putchar('0');
		static int Stk[30],tp=0;
		for(; x; x/=10) Stk[tp++]=x%10;
		while(tp) putchar(Stk[--tp]^48);
	}
	template<class T> void ptk(const T &x) {
		pt(x);putchar(' ');
	}
	template<class T> void ptn(const T &x) {
		pt(x);putchar('\n');
	}
	template<class T> bool chkmi(T &x,const T &y) {
		return x>y?x=y,true:false;
	}
	template<class T> bool chkmx(T &x,const T &y) {
		return x<y?x=y,true:false;
	}
}
using namespace Eddd;

const int Mod=998244353;

ll Fast(ll x,int b) {
	ll t=1;
	for(; b; b>>=1,x=x*x%Mod) {
		if(b&1) t=t*x%Mod;
	}
	return t;
}

const int N=4005;

int a[N],b[N],c[N],d[N];
ll f[N][N];
int n,m;

int ST[N][22];
int len[N];
int lg2[N];
int qmx(int l,int r) {
	int k=lg2[r-l+1];
	return min(ST[l][k],ST[r-len[k]+1][k]);
}
int solve(int L,int R) {
	if(L>R) return 0;
	int s=qmx(L,R);
	int x=d[s];
	
//	cerr << L << " " << R << " " << x << endl;
	
	int l=solve(L,x-1),cl=x-L;
	int r=solve(x+1,R),cr=R-x;
	FOR(i,1,R-L+1) f[x][i]=-2e18;
	FOR(i,0,cl) FOR(j,0,cr) {
		f[x][i+j]=max(f[x][i+j],f[l][i]+f[r][j]-1ll*a[x]*i*j*2);
//		if(x==4 && i && j) cerr << f[x][i+j] << " " << f[l][i]+f[r][j]-1ll*a[x]*i*j*2 << endl;
	}
	FOR(i,0,cl) FOR(j,0,cr) {
		f[x][i+j+1]=max(f[x][i+j+1],f[l][i]+f[r][j]+1ll*m*a[x]-1ll*a[x]*(1ll*i*j*2+i*2+j*2+1));
	}
//	if(x==4) cerr << f[l][1] << " " << f[r][1] <<  " " << f[x][2] << " " << a[x] << endl;
//	cerr << L << " " << R << " " << f[x][R-L+1] << endl;
	return x;
}
int main() {
	rd(n);rd(m);
	FOR(i,1,n) rd(a[i]),c[i]=a[i];
	sort(c+1,c+n+1);
	FOR(i,1,n) b[i]=lower_bound(c+1,c+n+1,a[i])-c-1;
	FOR(i,1,n) d[b[i]]=i;
	
	FOR(i,1,n) ST[i][0]=b[i];
	len[0]=1;lg2[1]=0;
	FOR(i,1,20) len[i]=len[i-1]<<1;
	FOR(i,2,n) lg2[i]=lg2[i>>1]+1;
	FOR(j,1,20) FOR(i,1,n) if(i+len[j-1]<=n) ST[i][j]=min(ST[i][j-1],ST[i+len[j-1]][j-1]);
	
	int p=solve(1,n);
//	cerr << f[4][2] << endl;
	ptn(f[p][m]);
	return 0;
}