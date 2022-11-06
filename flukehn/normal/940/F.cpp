#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC target("avx")
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,mod=1e9+7;
struct Frw{
    char *TT,*mo,but[(1<<15)+2],butt[(1<<15)+2],*bp,*bq;
    Frw(){bp=butt,bq=butt+(1<<15);}
    ~Frw(){fwrite(butt,1,bp-butt,stdout);}
    #define getc() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)
    #define RX {char c,f=1;while(!isdigit(c=getc()))f=c!='-';x=c-'0';\
        while(isdigit(c=getc()))x=x*10+c-'0';return f?x:-x;}
    inline operator int(){int x;RX;}
    inline void pr(char x){*bp=x;(++bp==bq)?fwrite(butt,1,1<<15,stdout),bp=butt:0;}
    inline void operator ()(int x){
        if(!x)return pr('0'),pr('\n');
        if(x<0)pr('-'),x=-x;
        static int s[12];int p=0;
        while(x)s[p++]=x%10,x/=10;
        per(i,0,p-1)pr(s[i]+'0');
		pr('\n');
    }
}it;
const int N=1e5+11;
int n,m;
int a[N],C[2*N];
int b[N],bel[N];
map<int,int> Mp;
struct Node{
	int l,r,id,x;
	bool operator<(const Node&t)const{
		return bel[l]!=bel[t.l]?l<t.l:(bel[r]!=bel[t.r]?r<t.r:x<t.x);
		//return a.l/3000==b.l/3000?(a.r/3000==b.r/3000?a.cur<b.cur:a.r/3000<b.r/3000):a.l<b.l;
	}
}q[N];
int X[N],Y[N],Z[N],ans[N];
int L,R,T,cnt;
inline void Del(int x){
	b[C[x]]--,b[--C[x]]++;
}
inline void Ins(int x){
	b[C[x]]--,b[++C[x]]++;
}
inline void change(int i){
	if(X[i]<=R&&X[i]>=L){
		Del(a[X[i]]);
		Ins(Y[i]);
	}
	Z[i]=a[X[i]];
	a[X[i]]=Y[i];
}
inline void chang1(int i){
	if(X[i]<=R&&X[i]>=L){
		Del(a[X[i]]);
		Ins(Z[i]);
	}
	a[X[i]]=Z[i];
}
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	n=it,m=it;
	int S=3400;
	rep(i,1,n)bel[i]=(i-1)/S;
	rep(i,1,n)a[i]=it;
	rep(i,1,n){
		if(!Mp[a[i]])Mp[a[i]]=++cnt;
		a[i]=Mp[a[i]];
	}
	int cur1=0,cur2=0;
	rep(i,1,m){
		int op=it,l=it,r=it;
		if(op==1)++cur1,q[cur1]=(Node){l,r,cur1,cur2};
		else{if(!Mp[r])Mp[r]=++cnt;X[++cur2]=l,Y[cur2]=Mp[r];}
	}
	L=1,R=1,T=0;
	C[a[1]]=1,b[1]=1;
	sort(q+1,q+cur1+1);
	rep(i,1,cur1){
		//cerr<<q[i].l<<" "<<q[i].r<<" "<<T<<" "<<q[i].x<<endl;
		rep(j,T+1,q[i].x)change(j);//a[X[i]]=Y[i];
		per(j,q[i].x+1,T)chang1(j);//a[X[i]]=Y[i];
		T=q[i].x;
		while(R<q[i].r)Ins(a[++R]);
		while(R>q[i].r)Del(a[R--]);
		while(L<q[i].l)Del(a[L++]);
		while(L>q[i].l)Ins(a[--L]);
		for(int j=1;;j++)if(!b[j]){ans[q[i].id]=j;break;}
	}
	rep(i,1,cur1)it(ans[i]);
}