#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef double db;
const int M=998244353;
const int maxn=1e6+10;
int b[maxn],nxt[maxn],pre[maxn],a[maxn],_,v[maxn],n;
vector<int> ans;
void add(int x,int y){
    while (x<maxn) b[x]+=y,x+=x&(-x);
}
int gs(int x){
	int ret=0; while (x) ret+=b[x],x-=x&(-x); return ret;
}
int f(int x){
	if (b[1]>x) return 0;
	int r,ret;
	for (int i=19;i>=0;i--) if (b[1<<i]<=x) {r=i;break;}
	ret=1<<r; x-=b[ret];
	for (int i=r-1;i>=0;i--) if (b[ret+(1<<i)]<=x) ret+=1<<i,x-=b[ret];
	return ret;
}
int getnxt(int x){
	int w=gs(x);
	if (w<gs(n)) return f(w)+1;
	return f(0)+1;
}
void work(){
	ans.clear();
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=n;i++) pre[i]=i-1,nxt[i-1]=i; pre[1]=n; nxt[n]=1;
	for (int i=1;i<=n;i++) if (__gcd(a[i],a[pre[i]])==1) add(i,1);
	int pos=1;
	while (gs(n)){
        int p=getnxt(pos); ans.pb(p); add(p,-1);
        if (p==nxt[p]) break;
        int u=pre[p],v=nxt[p];
        nxt[u]=v; pre[v]=u;
        if (__gcd(a[p],a[v])==1) add(v,-1);
        if (__gcd(a[u],a[v])==1) add(v,1);
        pos=v;
	}
	printf("%d",ans.size());
	for (auto x:ans) printf(" %d",x);puts("");
}
int main(){
	scanf("%d",&_);
	while (_--) work();
}