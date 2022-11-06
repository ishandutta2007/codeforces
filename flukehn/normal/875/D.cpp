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
const int N=200010;
#define top _top
int n,c[N];
int Le[N],Ri[N],stk[N],top;
ll ans,tot;
bool ck(int x){return (top&&(c[stk[top]]|c[x])==c[x]);}
int main(){
	n=rd();for(int i=1;i<=n;i++)c[i]=rd();
	for(int i=1;i<=n;i++){
		while(ck(i)&&(c[stk[top]]^c[i]))top--;
		Le[i]=stk[top]+1,stk[++top]=i;
	}
	top=0;
	for(int i=n;i;i--){
		while(ck(i))top--;
		Ri[i]=(!top)?n:stk[top]-1,stk[++top]=i;
	}
	ans=1LL*n*(n-1)/2;
	for(int i=1;i<=n;i++){
		tot+=(Ri[i]-Le[i]);
		tot+=1LL*(i-Le[i])*(Ri[i]-i);
	}
	cout<<ans-tot<<endl;
}