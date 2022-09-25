#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m;
vector<int> a[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		a[i].resize(m+1);
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	int x=0,y=0;
	for(int i=1;i<=n;++i){
		int mx=0,p=0;
		for(int j=1;j<=m;++j){
			if(a[i][j]<mx){
				p=j;
			}
			mx=max(mx,a[i][j]);
		}
		if(!p)continue;
		for(int k=p-1;k>=1;--k){
			if(a[i][k]>a[i][p]){
				x=k,y=p;
			}
		}
	}
	if(!x)x=y=1;
	for(int i=1;i<=n;++i){
		swap(a[i][x],a[i][y]);
		for(int j=1;j<m;++j){
			if(a[i][j]>a[i][j+1]){
				cout<<"-1\n";
				return;
			}
		}
	}
	cout<<x<<' '<<y<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}