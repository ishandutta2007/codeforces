#include<bits/stdc++.h>
using namespace std;
int n,a[1005],b[1005],used[1005];
struct Triple{
	int x,y,z;
};
void Solve(){
	vector<Triple> ans;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i],used[i]=0;
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		int p=lower_bound(b+1,b+n+1,a[i])-b;
		while(used[p])p++;
		a[i]=p,used[p]=1;
	}
	for(int i=1;i<=n;i++){
		int mn=1e9,mnp=0;
		for(int j=i;j<=n;j++)if(a[j]<mn)mn=a[j],mnp=j;
		if(mnp==i)continue;
		ans.push_back({i,mnp,mnp-i});
		for(int j=mnp;j>i;j--)a[j]=a[j-1];
		a[i]=mn;
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i.x<<' '<<i.y<<' '<<i.z<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}