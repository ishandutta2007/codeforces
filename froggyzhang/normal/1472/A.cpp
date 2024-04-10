#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,t;
void Solve(){
	cin>>n>>m>>t;
	int a=1;
	while(!(n&1))a<<=1,n>>=1;
	while(!(m&1))a<<=1,m>>=1;
	cout<<(a>=t?"YES\n":"NO\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}