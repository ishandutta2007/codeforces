#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],m;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>m;
	int now=1;
	for(int i=1;i<=m;++i){
		int x;
		cin>>x;
		now=(now+x-1)%n+1;
	}
	cout<<a[now]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}