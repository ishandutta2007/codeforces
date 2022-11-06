#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define For(i,a,b) rep(i,a,b-1)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=24;
int n,a[N],b[N],d[N],s[N];
inline bool cmp(int i,int j){return a[i]<a[j];}
bool dfs(int h,int t,int tot=0){
	if(!h)return tot<n-2;
	else if(t==n-1)return 0;
	else{
		return dfs(h-s[t],t+1,tot+1)||dfs(h,t+1,tot);
	}
}
int main(){
	n=rd();
	For(i,0,n)d[i]=i,a[i]=rd();
	sort(d,d+n,cmp);
	For(i,0,n)s[d[i]]=i;
	//For(i,0,n)cout<<d[i]<<endl;
	int mx=a[d[n-1]]-a[d[0]];
	For(i,0,n){
		b[i]=a[d[s[i]+1]];
	}
	b[d[n-1]]=a[d[0]];
	//For(i,0,n)cout<<b[i]<<endl;
	For(i,0,n-1)s[i]=b[d[i]]-a[d[i]];
	if(dfs(mx,0))puts("-1");
	else For(i,0,n)printf("%d%c",b[i]," \n"[i==n-1]);
}