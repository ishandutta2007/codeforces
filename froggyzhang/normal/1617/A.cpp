#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	string s,t;
	cin>>s>>t;
	sort(s.begin(),s.end());
	static int id[26];
	for(int i=0;i<26;++i)id[i]=i;
	int ok=0;
	for(auto x:s){
		if(x=='a')ok=1;
	}
	if(t=="abc"&&ok)swap(id[1],id[2]);
		sort(s.begin(),s.end(),[&](char c1,char c2){return id[c1-'a']<id[c2-'a'];});
		cout<<s<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}