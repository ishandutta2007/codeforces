#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
#define NO cout<<"NO\n";return;
int n,m,c[N];
map<int,int> mp;
void Solve(){
	cin>>n>>m;
	mp.clear();
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		--x;
		mp[y]|=1<<x;
	}
	int u=0;
	int las=0;
	for(auto [p,t]:mp){
		if(t==3){
			if(u){NO;}
		}
		else if(t==1){
			if(u==1){
				if((p&1)==(las&1)){NO;}
				u=0;	
			}
			else if(u==2){
				if((p&1)^(las&1)){NO;}
				u=0;
			}
			else u=1;
		}
		else{
			if(u==2){
				if((p&1)==(las&1)){NO;}
				u=0;	
			}
			else if(u==1){
				if((p&1)^(las&1)){NO;}
				u=0;
			}
			else u=2;
		}
		las=p;
	}
	if(u){NO;}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}