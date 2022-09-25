#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
inline bool chk(int z){
	return n-z>=2*z-1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	if(n==1){
		cout<<1<<'\n'<<1<<' '<<1<<'\n';
		return 0;
	}
	int p=1;
	while(chk(p+1))++p;
	cout<<n-p<<'\n';
	while(n-p!=2*p-1){
		cout<<n<<' '<<n<<'\n';
		--n;
	}
	for(int i=1;i<=p;++i){
		cout<<i<<' '<<2*i-1<<'\n';
	}
	for(int i=1;i<=p-1;++i){
		cout<<i+p<<' '<<2*i<<'\n';
	}
	return 0;
}