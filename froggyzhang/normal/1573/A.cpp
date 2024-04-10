#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int n;
	string s;
	cin>>n>>s;
	cout<<accumulate(s.begin(),s.end(),0,[&](int i,int x){return i+(x-'0')+(x>'0');})-(s.back()>'0')<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}