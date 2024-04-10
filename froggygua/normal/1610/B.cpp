#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N];
bool check(int x){
	int l=1,r=n;
	while(l<=r){
		while(l<=n&&a[l]==x)++l;
		while(r>=1&&a[r]==x)--r;
		if(l>r)break;
		if(a[l]^a[r])return false;
		++l,--r;
	}
	return true;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int l=1,r=n;
	while(l<=r&&a[l]==a[r])--r,++l;
	if(l>r){
		cout<<"YES\n";
		return;
	}
	if(check(a[l])||check(a[r])){
		cout<<"YES\n";	
	}
	else{
		cout<<"NO\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}