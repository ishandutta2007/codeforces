#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void Solve(){
	int a=1,b=1,c=1,n;
	cin>>n;
	while(n)a+=n%10*c,n/=10,b+=n%10*c,n/=10,c*=10;
	cout<<a*b-2<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}