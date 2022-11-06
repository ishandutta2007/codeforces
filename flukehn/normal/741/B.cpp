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
const int N=1011;
int n,w[N],b[N],siz[N];
int W[N],B[N];
int fa[N];
ll f[N];
vector<int> v[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	n=rd();int m=rd(),WW=rd();
	rep(i,1,n)w[i]=rd();
	rep(i,1,n)b[i]=rd();
	rep(i,1,n)fa[i]=i;
	
	rep(i,1,m){
		int u=rd(),v=rd();
		u=find(u),v=find(v);
		fa[u]=v;
	}
	rep(i,1,n){
		int u=find(i);
		if(u!=i){
			v[u].pb(i);
			W[u]+=w[i];
			B[u]+=b[i];
			siz[u]++;
		}
	}
	rep(i,1,n)if(siz[i])v[i].pb(i);
	rep(i,1,n)if(siz[i]){
		for(int j=WW;j>0;j--){
			for(auto u:v[i]){
				if(j>=w[u]){
					f[j]=max(f[j],f[j-w[u]]+b[u]);
				}
			}
			if(j>=W[i]+w[i]){
				f[j]=max(f[j],f[j-W[i]-w[i]]+B[i]+b[i]);
			}
		}
	}else if(find(i)==i){
		for(int j=WW;j>=w[i];j--){
			f[j]=max(f[j],f[j-w[i]]+b[i]);
		}
	}
	cout<<f[WW]<<endl;
}