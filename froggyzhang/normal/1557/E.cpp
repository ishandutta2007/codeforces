#include<bits/stdc++.h>
using namespace std;
const int n=8;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T;
pair<int,int> Ask(int x,int y){
	cout<<x<<" "<<y<<endl;
	static string s;
	cin>>s;
	if(s=="Right")return make_pair(0,1);
	if(s=="Left")return make_pair(0,-1);
	if(s=="Up")return make_pair(-1,0);
	if(s=="Down")return make_pair(1,0);
	if(s=="Down-Right")return make_pair(1,1);
	if(s=="Down-Left")return make_pair(1,-1);
	if(s=="Up-Left")return make_pair(-1,-1);
	if(s=="Up-Right")return make_pair(-1,1);
	return make_pair(0,0);
}
void Solve(){
	for(int i=1;i<=n;++i){
		if(i&1){
			for(int j=1;j<=n;++j){
				auto [px,py]=Ask(i,j);
				if(!px&&!py)return;
			}
		}
		else{
			for(int j=n;j>=1;--j){
				auto [px,py]=Ask(i,j);
				if(!px&&!py)return;
			}
		}
	}
	for(int i=n;i>=1;--i){
		if(i&1){
			for(int j=n;j>=1;--j){
				auto [px,py]=Ask(i,j);
				if(!px&&!py)return;
			}
		}
		else{
			for(int j=1;j<=n;++j){
				if(i==n&&j==1)continue;
				auto [px,py]=Ask(i,j);
				if(!px&&!py)return;
			}
		}	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}