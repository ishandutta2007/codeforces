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
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=111;
int a[N],n,d[N];
bool vis[N];
int main(){
	n=rd();
	rep(i,1,n)a[i]=rd(),d[a[i]]++;
	rep(i,1,n)if(!d[i]){
		puts("-1");
		return 0;
	}
	int x;
	ll mx=0;
	rep(i,1,n){
		if(!vis[i]){
			x=i;ll cnt=0;
			while(!vis[x]){
				vis[x]=1;
				x=a[x];
				cnt++;
			}
			if(!mx)mx=cnt;
			else mx=mx*cnt/__gcd(mx,cnt);
		}
	}
	cout<<((mx%2)?mx:mx/2)<<endl;
}