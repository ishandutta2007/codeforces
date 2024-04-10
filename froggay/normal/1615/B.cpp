#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int C=200000;
typedef long long ll;
int s[25][N];
void init(int n){
	for(int j=0;j<20;++j){
		for(int i=1;i<=n;++i){
			s[j][i]=s[j][i-1]+((i>>j&1)^1);	
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(C);
	int T;
	cin>>T;
	while(T--){
		int l,r;
		cin>>l>>r;
		int ans=2e9;
		for(int i=0;i<19;++i){
			ans=min(ans,s[i][r]-s[i][l-1]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}