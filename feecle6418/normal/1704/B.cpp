#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
int n,m,a[200005];
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int i=1,j;i<=n;i=j+1){
		ans++,j=i;
		int mx=a[i],mn=a[i];
		while(j<n&&max(mx,a[j+1])-min(mn,a[j+1])<=2*m)j++,mx=max(mx,a[j]),mn=min(mn,a[j]);
	}
	cout<<ans-1<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}