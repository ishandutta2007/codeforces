#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int n,a[25],b[25],ans;
void dfs(int x,int c){
	if(c>=ans)return ;
	if(x==0){
		int g=a[1];
		for(int i=1;i<=n;i++){
			g=__gcd(g,a[i]);
		}
		if(g==1)ans=min(ans,c);
		return ;
	}
	dfs(x-1,c);
	swap(a[x],b[x]);
	dfs(x-1,c+(n-x+1));
	swap(a[x],b[x]);
}
void Solve(){
	cin>>n,ans=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=__gcd(a[i],i);
	dfs(n,0),cout<<ans<<'\n';
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve(); 
}