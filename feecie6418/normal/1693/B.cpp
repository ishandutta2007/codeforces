#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,L[200005],R[200005],p[200005];
ll v[200005];
void Solve(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d%d",&L[i],&R[i]);
	int ans=0;
	for(int i=n;i>=1;i--){
		if(v[i]>R[i])v[i]=R[i];
		if(v[i]<L[i]){
			ans++;
			v[i]=R[i];
		}
		v[p[i]]+=v[i];
	}
	cout<<ans<<'\n';
	for(int i=0;i<=n;i++)v[i]=0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}