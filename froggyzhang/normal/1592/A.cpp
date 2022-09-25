#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,H,a[N];
void Solve(){
	cin>>n>>H;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	sort(a+1,a+n+1,greater<int>());
	cout<<H/(a[1]+a[2])*2+(H%(a[1]+a[2])>a[1])+(H%(a[1]+a[2])>0)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}