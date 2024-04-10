/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct zzz {
    int t, nex;
}e[500010 << 1]; int head[500010], tot;
void add(int x, int y) {
    e[++tot].t = y;
    e[tot].nex = head[x];
    head[x] = tot;
}
int depth[500001], fa[500001][22], lg[500001];
void dfs(int now, int fath) {
    fa[now][0] = fath; depth[now] = depth[fath] + 1;
    for(int i = 1; i <= lg[depth[now]]; ++i)
        fa[now][i] = fa[fa[now][i-1]][i-1];
    for(int i = head[now]; i; i = e[i].nex)
        if(e[i].t != fath) dfs(e[i].t, now);
}
int LCA(int x, int y) {
    if(depth[x] < depth[y]) swap(x, y);
    while(depth[x] > depth[y])
        x = fa[x][lg[depth[x]-depth[y]] - 1];
    if(x == y) return x;
    for(int k = lg[depth[x]] - 1; k >= 0; --k)
        if(fa[x][k] != fa[y][k])
            x = fa[x][k], y = fa[y][k];
    return fa[x][0];
}
int dis(int A,int B){
	if(LCA(A,B)==B) swap(A,B);
	if(LCA(B,A)==A){
		return  depth[B]-depth[A];
	} 
	else
	{
		return depth[B]+depth[A]-2*depth[LCA(B,A)];
	}
}
int main() {
    int n, m, s; scanf("%d", &n);
    for(int i = 1; i <= n-1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    for(int i = 1; i <= n; ++i)
        lg[i] = lg[i-1] + (1 << lg[i-1] == i);s=1;
    dfs(s, 0);
    int q;
    cin>>q;
    while(q--){
    	int x,y,a,b,k;
    	cin>>x>>y>>a>>b>>k;
    	int ok=0;
    	int m1,m2,m3,m4,m5;
    	m1=dis(a,x)+1+dis(y,b);
    	m2=dis(a,y)+1+dis(x,b);
    	m5=dis(a,b);
//    	cout<<dis(a,x)<<" "<<dis(y,b)<<" "<<m1<<" "<<m2<<" "<<k<<endl;
    	if(m1<=k&&(k-m1)%2==0) ok=1;
    	if(m2<=k&&(k-m2)%2==0) ok=1;
    	if(m5<=k&&(k-m5)%2==0) ok=1;
    	if(ok){
    		cout<<"yes"<<endl;
    	}
    	else cout<<"no"<<endl;
    }
    return 0;
}