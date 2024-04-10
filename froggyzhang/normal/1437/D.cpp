#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
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
int T,n,a[N];
int Solve(){
	queue<pair<int,int> > q;
	int ans=0,p=2;
	q.push(make_pair(1,0));
	while(!q.empty()){
		auto [u,h]=q.front();
		q.pop();
		ans=max(ans,h);
		int las=-1;
		while(p<=n&&a[p]>las)q.push(make_pair(a[p],h+1)),las=a[p++];
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		printf("%d\n",Solve());
	}
	return 0;
}