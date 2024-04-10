#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;//*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N = 2511;
typedef unsigned long long ull;
int n,m;
struct BIT{
	ull R[N];
	void TMD(int l,int r,ull ta){
		for(int i=r;i>=1;i^=(i&-i))
			R[i]^=ta;
		for(int i=l-1;i>=1;i^=(i&-i))
			R[i]^=ta;
	}
	ull Que(int x){
		ull sep=0;
		for(int i=x;i<= m;i+=(i&-i))
			sep^=R[i];
		return sep;
	}
};
struct BIT2{
	BIT R[N];
	void TMD(int l, int r, int ll, int rr,ull ta){
	#define fffefsaf
			#undef fffefsaf
		for(int i=r;i>= 1;i^=(i&-i))R[i].TMD(ll, rr, ta);
		for(int i=l-1;i>=1;i^=(i&-i))R[i].TMD(ll, rr, ta);
	}
	ull Que(int x, int y){
	#define fffefsaf
			#undef fffefsaf
		ull sep=0;
		for (int i=x;i<=n;i+=(i&-i))sep^=R[i].Que(y);
		return sep;
	}
};
inline ull get233(){
#define fffefsaf
			#undef fffefsaf
	static minstd_rand0 gen(chrono::system_clock().now().time_since_epoch().count());
	return ull(gen()) << 32 | gen();
}
map<ull, ull> FFF;
BIT2 bit;
int main(){
	int q;
	n=rd(),m=rd(),q=rd();
	while (q--){
		int t=rd(),r=rd(),c=rd(),R=rd(),C=rd();
		if(t==1){
			ull HR = r+N*(R+N *(c+N*C));
			bit.TMD(r,R,c,C,FFF[HR]=get233());
			#define fffefsaf
			#undef fffefsaf
		}
		else if (t==2){
			ull h = r + N * (R + N * (c + N * C));
			auto ITR = FFF.find(h);
			bit.TMD(r, R, c, C, ITR->y);
			FFF.erase(ITR);
			#define fffefsaf
			#undef fffefsaf
		}
		else puts(bit.Que(r,c)==bit.Que(R,C)?"Yes":"No");
	}
}