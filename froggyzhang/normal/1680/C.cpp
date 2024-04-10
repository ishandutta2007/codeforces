#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n;
char s[N];
void Solve(){
	cin>>(s+1);
	n=strlen(s+1);
	int A=0,B=0;
	for(int i=1;i<=n;++i){
		A+=s[i]=='1';
	}
	int ans=n;
	for(int i=1,j=1;i<=n;++i){
		if(s[i]=='1')--A;
		else ++B;
		ans=min(ans,max(A,B));
		while(j<=i&&A<=B){
			A+=s[j]=='1';
			B-=s[j]=='0';
			ans=min(ans,max(A,B));
			++j;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}