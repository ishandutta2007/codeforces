#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n;
char s[N];
void Solve(){
	cin>>n;
	cin>>(s+1);
	int ans=n&1;
	for(int i=n/2;i>=1;--i){
		if(s[i+1]^s[n-i+1])break;
		ans+=2;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}