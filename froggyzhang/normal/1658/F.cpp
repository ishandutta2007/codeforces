#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m,sum[N];
char s[N];
void Solve(){
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;++i){
		sum[i]=(sum[i-1]+(s[i]=='1'));
	}
	int A=sum[n];
	if(1LL*m*A%n){
		cout<<-1<<'\n';
	}
	else{
		int B=1LL*m*A/n;
		for(int i=m;i<=n;++i){
			if(sum[i]-sum[i-m]==B){
				cout<<1<<'\n';
				cout<<i-m+1<<' '<<i<<'\n';
				return;
			}
		}
		for(int i=1;i<=m;++i){
			if(sum[i]+sum[n]-sum[n-(m-i)]==B){
				cout<<2<<'\n';
				cout<<1<<' '<<i<<'\n';
				cout<<n-(m-i)+1<<' '<<n<<'\n';
				return;
			}
		}
		assert(false);
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