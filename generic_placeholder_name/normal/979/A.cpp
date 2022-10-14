//author: dmk
#include <bits/stdc++.h>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin>>n;
	if (n==0) cout<<0;
	else if ((n+1)%2==0) cout<<(n+1)/2;
	else cout<<n+1;
}