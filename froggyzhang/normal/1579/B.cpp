#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
int n,a[N],b[N];
void Solve(){
	vector<tuple<int,int,int> > ans;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=a[i];	
	}
	sort(b+1,b+n+1);
	for(int i=1;i<n;++i){
		if(a[i]==b[i])continue;
		for(int j=i+1;j<=n;++j){
			if(a[j]==b[i]){
				ans.emplace_back(i,n,j-i);
				rotate(a+i,a+j,a+n+1);
				break;	
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(auto [x,y,z]:ans){
		cout<<x<<' '<<y<<' '<<z<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}