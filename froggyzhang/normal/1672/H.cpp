#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,Q,pre[2][N];
char s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	cin>>(s+1);
	for(int i=1;i<=n;++i){
		for(int j=0;j<2;++j){
			pre[j][i]=pre[j][i-1]+(s[i-1]==j+'0'&&s[i]==j+'0');
		}
	}
	while(Q--){
		int l,r;
		cin>>l>>r;
		cout<<max(pre[0][r]-pre[0][l],pre[1][r]-pre[1][l])+1<<'\n';
	}
	return 0;
}