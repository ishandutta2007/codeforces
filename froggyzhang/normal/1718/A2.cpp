#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N];
void Solve(){
	set<int> S;
	cin>>n;
	int now=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	S.insert(0);
	int ans=n;
	for(int i=1;i<=n;++i){
		now^=a[i];
		if(S.count(now)){
			--ans;
			S.clear();
			S.insert(0);
			now=0;
		}
		S.insert(now);
	}
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