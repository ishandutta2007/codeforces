#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
void Solve(){
	cin>>n;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n/2;++i){
		if(s[i]=='0'){
			printf("%d %d %d %d\n",i,n,i+1,n);
			return;
		}
	}
	for(int i=n/2+1;i<=n;++i){
		if(s[i]=='0'){
			printf("%d %d %d %d\n",1,i,1,i-1);
			return;
		}
	}
	printf("%d %d %d %d\n",1,n/2*2,1,n/2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}