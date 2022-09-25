#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int l,r;
	cin>>l>>r;
	printf("%d\n",r%max(r/2+1,l));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}