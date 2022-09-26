#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int T,n,m,a[N];
void Solve(){
	n=read(),m=read();
	read();
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=m;++i){
		q.push(make_pair(0,i));
	}
	printf("YES\n");
	for(int i=1;i<=n;++i){
		auto [t,u]=q.top();
		q.pop();
		t+=a[i];
		printf("%d ",u);
		q.push(make_pair(t,u));
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}