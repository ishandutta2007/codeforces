#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s,n,a[12];
void Solve(){
	cin>>s>>n;
	for(int i=1;i<n;++i){
		int j=pow(10,(int)log10(s-n+i));
		cout<<j<<' ';s-=j;
	}
	cout<<s<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}