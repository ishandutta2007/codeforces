#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
bool check(string s){
	int cnt[3]={0,0,0};
	for(auto x:s)++cnt[x-'a'];
	return cnt[0]>cnt[1]&&cnt[0]>cnt[2];	
}
void Solve(){
	cin>>n;
	cin>>s;
	for(int len=2;len<=10;++len){
		for(int i=0;i+len-1<n;++i){
			if(check(s.substr(i,len))){
				cout<<len<<'\n';
				return;
			}
		}
	}
	cout<<-1<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}