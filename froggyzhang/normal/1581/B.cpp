#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
bool Solve(){
	cin>>n>>m>>k;
	--k;
	if(m<n-1||m>1LL*n*(n-1)/2)return false;
	if(n==1)return k>=1;
	if(n==2)return k>=2;
	if(m==1LL*n*(n-1)/2)return k>=2;
	return k>=3;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cout<<(Solve()?"YES\n":"NO\n");
	}
	return 0;
}