#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	string s;
	cin>>s;
	int cnt=0,A=0,B=0;
	for(int i=0;i<(int)s.length();++i){
		cnt+=s[i]-'0';
		if(s[i]=='0')++B;
		else if((s[i]-'0')%2==0)++A;
	}
	cout<<((B>=1&&A+B>=2&&cnt%3==0)?"red\n":"cyan\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}