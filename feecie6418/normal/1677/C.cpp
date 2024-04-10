#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,a[100005],b[100005],fa[100005],sz[100005];
ll ans;
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),fa[i]=i,sz[i]=0;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),fa[gf(a[i])]=gf(b[i]);
	for(int i=1;i<=n;i++)sz[gf(i)]++;
	int s=0;
	for(int i=1;i<=n;i++)if(gf(i)==i&&sz[i]%2==1)s++;
	if(n%2==0){
		ans=0;
		for(int i=1;i<=n/2;i++)ans-=2*i;
		for(int i=n/2+1;i<=n;i++)ans+=2*i;
		for(int i=1;i<=s/2;i++){
			ans-=4*i-2;
		}
		cout<<ans<<'\n';
	}
	else {
		ans=0;
		for(int i=1;i<=n/2;i++)ans-=2*i;
		for(int i=n/2+2;i<=n;i++)ans+=2*i;
		for(int i=1;i<=(s-1)/2;i++){
			ans-=4*i;
		}
		cout<<ans<<'\n';
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}