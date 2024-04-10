#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
char c;
int n;
void Solve(){
	cin>>n>>c>>s;
	s=' '+s;
	bool same=true;
	for(int i=1;i<=n;++i){
		if(s[i]^c)same=false;
	}
	if(same){
		cout<<0<<'\n';
		return;
	}
	for(int i=2;i<=n;++i){
		int ok=1;
		for(int j=i;j<=n;j+=i){
			if(s[j]^c){
				ok=0;break;
			}
		}
		if(ok){
			cout<<1<<'\n'<<i<<'\n';
			return;
		}
	}
	cout<<2<<'\n'<<n<<' ';
	for(int i=2;i<=n;++i){
		if(n%i){
			cout<<i<<'\n';
			return;
		}
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