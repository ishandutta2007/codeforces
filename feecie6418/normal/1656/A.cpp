#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,a[100005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<(min_element(a+1,a+n+1)-a)<<' '<<(max_element(a+1,a+n+1)-a)<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}