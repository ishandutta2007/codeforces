#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	string s;
	cin>>s;
	if(s.back()!='B'){
		cout<<"No\n";
		return;
	}
	int now=0;
	for(auto c:s){
		if(c=='A')++now;
		else --now;
		if(now<0){
			cout<<"No\n";
			return;
		}
	}
	cout<<"Yes\n";
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}