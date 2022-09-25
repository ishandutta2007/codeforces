#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int x,y;
	cin>>x>>y;
	if(!x&&!y){
		cout<<0<<'\n';
	}
	else{
		int w=sqrt(x*x+y*y);
		if(w*w==x*x+y*y){
			cout<<1<<'\n';
		}
		else{
			cout<<2<<'\n';
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