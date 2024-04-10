#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
void Solve(){
	cin>>n;
	ll tmp=1;
	while(n%2==0)n>>=1,tmp<<=1;
	if(n==1){
		cout<<-1<<'\n';
	}
	else{
		cout<<min(2*tmp,n)<<'\n';
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