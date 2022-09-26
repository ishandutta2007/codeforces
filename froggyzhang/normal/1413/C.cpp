#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define N 100020
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
int n,a[7],b[N],mx,ans,t[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int main(){
	for(int i=1;i<=6;++i){
		a[i]=read();
	}
	n=read();
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	sort(a+1,a+6+1,greater<int>());
	for(int i=1;i<=n;++i){
		t[i]=1;
		q.push(make_pair(b[i]-a[1],i));
		mx=max(mx,b[i]-a[1]);
	}
	ans=0x7fffffff;
	while(true){
		int u=q.top().second;
		ans=min(ans,mx-q.top().first);
		q.pop();
		if(t[u]==6)break;
		++t[u];
		mx=max(mx,b[u]-a[t[u]]);
		q.push(make_pair(b[u]-a[t[u]],u));
	}
	printf("%d\n",ans);
	return 0;
}