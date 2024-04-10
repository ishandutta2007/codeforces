#include<bits/stdc++.h>
using namespace std;
#define N 500050
#define M 777
const int n=500000;
const int B=700;
typedef long long ll;
int cnt[M][M],Q,a[N]; 
void Solve(){
	cin>>Q;
	while(Q--){
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt==1){
			for(int i=1;i<=B;++i){
				cnt[i][x%i]+=y;	
			}
			a[x]+=y;
		}
		else{
			int ans=0;
			if(x<=B){
				ans=cnt[x][y];	
			}
			else{
				for(int i=y;i<=n;i+=x){
					ans+=a[i];	
				}
			}
			cout<<ans<<'\n';
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}