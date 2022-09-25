#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
int n,a[N],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	ans=n;
	for(int i=1;i<=n;++i){	
		set<int> vis;
		for(int j=1;j<i;++j){
			if(vis.count(a[j]))goto ed;
			vis.insert(a[j]);
		}
		for(int j=n;j>=i-1;--j){
			ans=min(ans,j-i+1);
			if(vis.count(a[j]))break;
			vis.insert(a[j]);
		}
		ed:;
	}
	cout<<ans<<'\n';
	return 0;
}