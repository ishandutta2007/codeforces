#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
void Solve(){
	cin>>n;
	cin>>s;
	int ans=1e9;
	for(char c='a';c<='z';++c){
		int i=0,j=n-1;
		int tmp=0;
		while(i<j){
			int ti=0,tj=0;
			while(i<n&&s[i]==c)++i,++ti;
			while(j>=0&&s[j]==c)--j,++tj;
			if(i>j)break;
			if(s[i]^s[j]){
				tmp=1e9;
				break;
			}
			tmp+=max(ti,tj)-min(ti,tj);
			++i,--j;
		}
		ans=min(ans,tmp);
	}
	if(ans==1e9){
		cout<<-1<<'\n';
	}
	else{
		cout<<ans<<'\n';
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