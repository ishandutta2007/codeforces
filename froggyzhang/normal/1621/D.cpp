#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
int c[N][N],n;
ll JB(){
	ll tot=0;
	for(int i=n+1;i<=n<<1;++i){
		for(int j=n+1;j<=n<<1;++j){
			tot+=c[i][j];
		}
	}
	return tot;
}
ll calc(){
	return min(min(min(c[1][n+1],c[1][n*2]),min(c[n][n+1],c[n][n*2])),
		       min(min(c[n+1][1],c[n*2][1]),min(c[n+1][n],c[n*2][n])));
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n<<1;++i){
		for(int j=1;j<=n<<1;++j){
			cin>>c[i][j];
		}
	}
	cout<<calc()+JB()<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}