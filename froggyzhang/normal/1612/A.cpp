#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int x,y;
	cin>>x>>y;
	if((x+y)&1){
		cout<<-1<<' '<<-1<<'\n';
		return;
	}
	for(int i=0;i<=50;++i){
		for(int j=0;j<=50;++j){
			if(i+j==(x+y)/2&&abs(x-i)+abs(y-j)==(x+y)/2){
				cout<<i<<' '<<j<<'\n';
				return;
			}		
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}