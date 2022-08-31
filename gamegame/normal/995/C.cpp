#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
int lc[200001],rc[200001];
bool inv[200001];
bool ans[200001];
ll x[200001],y[200001];
int rt1,rt2;
int p[3];
ll len(ll xx,ll yy){
	return xx*xx+yy*yy;
}
void dfs(int id){
	if(lc[id]==0) return;
	ans[lc[id]]=ans[id]^inv[lc[id]];
	ans[rc[id]]=ans[id]^inv[rc[id]];
	dfs(lc[id]);
	dfs(rc[id]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	if(n==1){
		cout << "1\n";
		return 0;
	}
	for(int i=1; i<=n ;i++){
		cin >> x[i] >> y[i];
	}
	rt1=1,rt2=2;
	for(int i=3; i<=n ;i++){
		p[0]=rt1,p[1]=rt2,p[2]=i;
		sort(p,p+3);
		do{
			if(len(x[p[0]]+x[p[1]],y[p[0]]+y[p[1]])<=1e12){
				x[n+i]=x[p[0]]+x[p[1]];
				y[n+i]=y[p[0]]+y[p[1]];
				lc[n+i]=p[0],rc[n+i]=p[1];
				rt1=n+i;
				rt2=p[2];
				break;
			}
			if(len(x[p[0]]-x[p[1]],y[p[0]]-y[p[1]])<=1e12){
				x[n+i]=x[p[0]]-x[p[1]];
				y[n+i]=y[p[0]]-y[p[1]];
				lc[n+i]=p[0],rc[n+i]=p[1];
				rt1=n+i;
				inv[p[1]]=true;
				rt2=p[2];
				break;
			}
		}while(next_permutation(p,p+3));
	}
	if(len(x[rt1]-x[rt2],y[rt1]-y[rt2])<=2e12) inv[rt2]=true;
	ans[rt1]=inv[rt1];ans[rt2]=inv[rt2];
	dfs(rt1);
	dfs(rt2);
	for(int i=1; i<=n ;i++){
		if(ans[i]) cout << "-1 ";
		else cout << "1 ";
	}
}