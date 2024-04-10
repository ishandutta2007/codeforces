#include<bits/stdc++.h>
using namespace std;
#define N 55
typedef long long ll;
int n;
char s[N];
void Solve(){
	cin>>n;
	cin>>(s+1);
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int p=0;
			for(int k=i;k<=j;++k)p+=s[k]=='a'?1:-1;
			if(!p){
				cout<<i<<' '<<j<<'\n';
				return;
			}		
		}
	}
	cout<<-1<<' '<<-1<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}