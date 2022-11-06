#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define I inline
#define OP operator
#define pb push_back
#define mp make_pair
#define RT return *this
#define dbg(x) cerr<<#x" = "<<x<<endl
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)
I bool IS(char x){return x==10||x==13||x==' ';}
struct Cg{I char OP()(){return getchar();}};struct Cp{I void OP()(char x){putchar(x);}};
#define RX char c,f=1;while(!isdigit(c=P()))f=c!='-';x=c-'0';while(isdigit(c=P()))x=x*10+c-'0';x=f?x:-x
struct Fr{Cg P;I Fr&OP,(int&x){RX;RT;}I Fr&OP,(ll &x){RX;RT;}I Fr&OP,(char&x){while(IS(x=P()));RT;}
I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS(t)&&~t;t=P())*x++=t;}*x++=0;RT;}}in;
#define WI if(x){if(x<0)P('-'),x=-x;char s[22],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
struct Fw{Cp P;I Fw&OP,(int x){WI;RT;}I Fw&OP,(ll x){WI;RT;}I Fw&OP,(char x){P(x);RT;}
I Fw&OP,(const char *x){while(*x)P(*x++);RT;}}out;
const int N=100011;
int sz[N],cnt,n,p[N];
bool vis[N];
int main(){
	in,n;
	rep(i,1,n){
		in,p[i];
	}
	ll ans=0;
	rep(i,1,n)if(!vis[i]){
		int x=i,t=0;
		while(!vis[x]){
			vis[x]=1,x=p[x],t++;
		}
		sz[++cnt]=t;
		ans+=1LL*t*t;
	}
	if(cnt==1)printf("%lld\n",ans);
	else{
		sort(sz+1,sz+n+1);
		ans+=2LL*sz[n]*sz[n-1];
		printf("%lld\n",ans);
	}
}