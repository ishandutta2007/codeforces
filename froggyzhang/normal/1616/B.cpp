#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
char s[N];
void Solve(){
	int n;
	cin>>n>>(s+1);
	for(int i=1;i<=n;++i){
		if(i==n||s[i+1]>s[i]||(i==1&&s[i]==s[i+1])){
			for(int j=1;j<=i;++j)cout<<s[j];
			for(int j=i;j>=1;--j)cout<<s[j];
			cout<<'\n';
			return;	
		}
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