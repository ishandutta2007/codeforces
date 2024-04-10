#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200020
int n,a[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cout<<(min_element(a+1,a+n+1)-a)<<' '<<(max_element(a+1,a+n+1)-a)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}