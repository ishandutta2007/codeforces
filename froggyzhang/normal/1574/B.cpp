#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int a,b,c,m;
	cin>>a>>b>>c>>m;
	int r=max(a-1,0)+max(b-1,0)+max(c-1,0);
	int l=max(0,max(max(a,b),c)-(a+b+c-max(max(a,b),c))-1);
	cout<<(m>=l&&m<=r?"YES\n":"NO\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}