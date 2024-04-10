#include<bits/stdc++.h>
using namespace std;
#define N 300030
const int mx=300001;
typedef long long ll;
int s[N];
void Solve(){
	int a,b;
	cin>>a>>b;
	if(s[a-1]==b){
		cout<<a<<'\n';
	}
	else if(s[a]^b){
		cout<<a+1<<'\n';
	}
	else{
		cout<<a+2<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=mx;++i){
		s[i]=s[i-1]^i;
	}
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}