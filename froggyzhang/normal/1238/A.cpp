#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		ll a,b;
		cin>>a>>b;
		puts(a==b+1?"NO":"YES");
	}
	return 0;
}