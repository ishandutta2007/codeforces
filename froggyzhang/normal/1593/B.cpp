#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	string s;
	cin>>s;
	int n=s.length();
	s=' '+s;
	int cnt[10]={};
	for(int i=n;i>=1;--i){
		int c=s[i]-'0';
		if((!c||c==5)&&cnt[0]||(c==2||c==7)&&cnt[5]){
			cout<<n-i-1<<'\n';
			return;
		}
		++cnt[c];
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