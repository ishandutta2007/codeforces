#include<bits/stdc++.h>
using namespace std;
long long n, a, b, c, ans, ji;
int main(){
	cin>>n>>a>>b>>c;
	if (n >= b && b - c <= a){
		ans = (n-b)/(b-c) + 1;
		n -= (b-c)*ans;
	}
	ans += n/a;
	cout<<ans<<endl;
	return 0;
}