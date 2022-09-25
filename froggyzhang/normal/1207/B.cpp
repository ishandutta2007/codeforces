#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
int n,m,a[N][N],b[N][N];
vector<pair<int,int> > ans;
void Solve(){
	cin>>n>>m;
	ans.clear();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			b[i][j]=0;
		}
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<m;++j){
			if(a[i][j]&a[i+1][j]&a[i][j+1]&a[i+1][j+1]){
				ans.emplace_back(i,j);
				b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]^b[i][j]){
				puts("-1");return;
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(auto [x,y]:ans){
		cout<<x<<" "<<y<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}