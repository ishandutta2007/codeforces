#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n,Q,ans;
int check(int p){
	if(p<0||p+3>n)return 0;	
	return s[p]=='a'&&s[p+1]=='b'&&s[p+2]=='c';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	cin>>s;
	for(int i=0;i<n;++i){
		ans+=check(i);
	}
	while(Q--){
		int p;
		char c;
		cin>>p>>c;
		--p;
		for(int i=-5;i<=5;++i)ans-=check(p+i);
		s[p]=c;
		for(int i=-5;i<=5;++i)ans+=check(p+i);
		cout<<ans<<'\n';	
	}
	return 0;
}