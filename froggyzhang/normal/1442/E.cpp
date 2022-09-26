#include<bits/stdc++.h>
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
int T,n,a[N],d[N];
vector<int> G[N];
int Solve(int x){
	deque<int> q;
	int ans=1;
	int now=x;
	for(int i=1;i<=n;++i){
		d[i]=G[i].size(); 
		if(d[i]==1){
			if(a[i]==x||!a[i])q.push_front(i);
			else q.push_back(i);
		}
	}	
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		if((a[u]|now)==3)now=a[u],++ans;
		for(auto v:G[u]){
			if((--d[v])==1){
				if((a[v]|now)==3)q.push_back(v);
				else q.push_front(v);
			}	
		}	
	}
	return ans;
} 
void Solve(){
	n=read();
	for(int i=1;i<=n;++i)G[i].clear(),a[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}	
	printf("%d\n",min(Solve(1),Solve(2)));
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}