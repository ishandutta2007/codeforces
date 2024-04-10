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
int n,m,Q,ans;
set<int,greater<int> > s[N];
void Insert(int u,int v){
	ans-=(*s[u].begin())<=u;
	ans-=(*s[v].begin())<=v;
	s[u].insert(v);
	s[v].insert(u);
	ans+=(*s[u].begin())<=u;
	ans+=(*s[v].begin())<=v;	
}
void Del(int u,int v){
	ans-=(*s[u].begin())<=u;
	ans-=(*s[v].begin())<=v;
	s[u].erase(v);
	s[v].erase(u);
	ans+=(*s[u].begin())<=u;
	ans+=(*s[v].begin())<=v;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		s[i].insert(0);
	}
	ans=n;
	while(m--){
		int u=read(),v=read();
		Insert(u,v);
	}
	Q=read();
	while(Q--){
		int opt=read();
		if(opt==1||opt==2){
			int u=read(),v=read();
			opt==1?Insert(u,v):Del(u,v);
		}
		else{
			printf("%d\n",ans);
		}	
	}
	return 0;
}