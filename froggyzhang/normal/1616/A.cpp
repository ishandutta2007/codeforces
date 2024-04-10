#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 233
int n,a[N];
void Solve(){
	set<int> s;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(s.count(a[i]))s.insert(-a[i]);
		s.insert(a[i]);
	}
	cout<<s.size()<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}