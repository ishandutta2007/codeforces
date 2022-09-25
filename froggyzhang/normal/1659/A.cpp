#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
void Solve(){
	cin>>n>>a>>b;
	string s="";
	for(int i=1;i<=b+1;++i){
		for(int j=0;j<a/(b+1)+(a%(b+1)>=i);++j){
			s+="R";
		}
		if(i<=b)s+="B";
	}
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