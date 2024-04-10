#include<bits/stdc++.h>
using namespace std;
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
int T,n;
vector<tuple<int,int,int> > ans;
void Solve(int i,int j){
	ans.emplace_back(1,i,j);
	ans.emplace_back(2,i,j);
	ans.emplace_back(1,i,j);
	ans.emplace_back(1,i,j);
	ans.emplace_back(2,i,j);
	ans.emplace_back(1,i,j);
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		read();
	}
	ans.clear();
	for(int i=1;i<=n;i+=2){
		Solve(i,i+1);
	}
	printf("%d\n",(int)ans.size());
	for(auto [x,y,z]:ans){
		printf("%d %d %d\n",x,y,z);
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}