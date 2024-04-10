#include<bits/stdc++.h>
using namespace std;
int n,K,m,a[2000005],b[2000005];
int Solvee(){
	int pos=-1;
	for(int j=0;j<m;j++)if(b[j]==0)pos=j;
	if(pos==-1)return 1e9;
	for(int j=0;j<m;j++)b[j+m]=b[j];
	int ans=0;
	for(int j=pos,lst=j;j<pos+m;j++){
		if(!b[j]){
			lst=j;
			continue;
		}
		ans=max(ans,j-lst);
	}
	return ans;
}
void Solve(){
	scanf("%d%d",&n,&K);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int i=0,g=__gcd(n,K);i<g;i++){
		m=0,b[m++]=a[i];
		for(int j=(i+K)%n;j!=i;j+=K,j%=n)b[m++]=a[j];
		reverse(b,b+m);
		ans=max(ans,Solvee());
	}
	if(ans!=1e9)cout<<ans<<'\n';
	else puts("-1");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}