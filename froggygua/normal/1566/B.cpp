#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
char s[N];
int n;
void Solve(){
	cin>>(s+1);
	n=strlen(s+1);
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='0'&&(i==n||s[i+1]=='1'))++cnt;	
	}
	cout<<min(2,cnt)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}