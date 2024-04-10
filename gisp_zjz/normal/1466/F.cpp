#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
const int M=1000000007;
int _,n,pre[maxn],cnt,m;
vector<int> ans;
int ffind(int x){
	if (pre[x]==x) return x;
	return pre[x]=ffind(pre[x]);
}
int main(){
	scanf("%d%d",&n,&m); cnt=1;
	for (int i=0;i<=m;i++) pre[i]=i;
	for (int i=1;i<=n;i++){
		int x,u,v;scanf("%d",&x);
		if (x==1){
			scanf("%d",&u); v=0;
		} else {
			scanf("%d%d",&u,&v);
		}
		u=ffind(u); v=ffind(v);
		if (u!=v) {
			cnt=cnt*2%M;
			ans.pb(i);
			pre[v]=u;
		}
	}
	printf("%d %d\n",cnt,(int)ans.size());
	for (auto x:ans) printf("%d ",x);puts("");
	return 0;
}