#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 300030
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
int T,n,ans[N];
vector<int> p[N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i].clear();
		ans[i]=0;
	}
	for(int i=1;i<=n;++i){
		p[read()].push_back(i);
	}
	ans[1]=1;
	for(int i=1;i<=n;++i){
		if((int)p[i].size()!=1){
			ans[1]=0;break;
		}
	}
	for(int i=1,l=1,r=n;i<n;++i){
		if(p[i].size()>1){
			ans[r-l+1]=1;break;
		}
		else if(p[i].empty()){
			break;
		}
		else{
			ans[r-l+1]=1;
			if(p[i][0]==l)++l;
			else if(p[i][0]==r)--r;
			else break;
		}
	}
	for(int i=1;i<=n;++i){
		putchar(ans[i]+'0');
	}
	putchar('\n');
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}