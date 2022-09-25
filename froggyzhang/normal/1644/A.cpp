#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void Solve(){
	cin>>s;
	int r=0,g=0,b=0;
	for(auto c:s){
		if(c=='r')++r;
		else if(c=='g')++g;
		else if(c=='b')++b;
		else if(c=='R')--r;
		else if(c=='G')--g;
		else --b;
		if(r<0||g<0||b<0){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}