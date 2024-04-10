#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	ll now=0;
	for(int i=1;i<=n;++i){
		if((i&1)^(a[i]&1))now+=i&1?a[i]:-a[i];	
	}
	if(!now)cout<<"Tie\n";
	else if(now>0)cout<<"Alice\n";
	else cout<<"Bob\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}