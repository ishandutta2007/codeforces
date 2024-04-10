#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int p[200001];
int mdif,md;
void solve(){
	mdif=md=0;
	int n;cin >> n;
	int x;cin >> x;
	for(int i=1; i<=n ;i++){
		int di,hi;cin >> di >> hi;
		mdif=max(mdif,di-hi);
		md=max(md,di);
	}
	if(x<=md) cout << "1\n";
	else if(mdif==0) cout << "-1\n";
	else cout << (x-md+mdif-1)/mdif+1 << '\n';
}
int main(){
	int t;cin >> t;
	while(t--) solve();
}