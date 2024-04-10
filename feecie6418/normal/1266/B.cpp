#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	ll n;
	cin>>n;
	if(n%14>=1&&n%14<=6&&n>=14)puts("Yes");
	else puts("No");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}