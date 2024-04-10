#include<bits/stdc++.h>
using namespace std;
#define N 233
typedef long long ll;
int n,a[N],m,b[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>b[i];
	}
	int mxa=*max_element(a+1,a+n+1);
	int mxb=*max_element(b+1,b+m+1);
	cout<<(mxa>=mxb?"Alice\n":"Bob\n");
	cout<<(mxb>=mxa?"Bob\n":"Alice\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}