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
int T,n,p[N];
ll W,a[N];
void Solve(){
	for(int i=1;i<=n;++i){
		a[i]=read();
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return a[i]>a[j];});
	static vector<int> ans;
	ans.clear();
	ll now=0;
	for(int i=1;i<=n;++i){
		if(now+a[p[i]]<=W){
			now+=a[p[i]];
			ans.push_back(p[i]);
		}
		if(now>=(W+1)/2)break;
	}
	if(now<(W+1)/2){
		printf("-1\n");
		return;
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d ",x);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		n=read(),W=read();
		Solve();
	}
	return 0;
}