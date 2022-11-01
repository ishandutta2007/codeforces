#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
int n,w[N][N];
const int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int work(){
	int ans=0;
	for(int i=2;i<=n<<1;i+=4){
		for(int j=1,op=1;j<=n;++j){
			int k=i-j;
			if(k>=1&&k<=n){
				if(op)ans^=w[j][k];
				op^=1;
			}
		}
	}
	return ans;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>w[i][j];
		}
	}
	int ans=0;
	ans^=work();
	for(int i=1;i<=n;++i){
		reverse(w[i]+1,w[i]+n+1);
	}
	ans^=work();
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}