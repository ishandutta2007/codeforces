#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200020
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
vector<int> p[N];
int Solve(){
	n=read();
	for(int i=1;i<=n;++i)p[i].clear();
	for(int i=1;i<=n;++i){
		p[read()].push_back(i);
	}
	int ans=n;
	for(int i=1;i<=n;++i){
		if(p[i].empty())continue;
		int tmp=0,las=0;
		for(auto x:p[i]){
			if(x-las>1)++tmp;
			las=x;
		}
		if(p[i].back()<n)++tmp;
		ans=min(ans,tmp);
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}