#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
void Solve(){
	int cnt[3]={0,0,0};
	cin>>s;
	for(auto c:s){
		++cnt[c-'A'];
	}
	if(cnt[0]+cnt[2]==cnt[1]){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
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