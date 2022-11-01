#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	bool _1=false,_2=false;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==1)_1=true;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		if(a[i]-a[i-1]==1)_2=true;
	}
	cout<<(_1&&_2?"NO\n":"YES\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}