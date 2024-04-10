#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 3030
const ll inf=0x3f3f3f3f3f3f3f3fll;
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
int n,m;
ll ans;
vector<int> c[N];
ll Solve(int x){
	static vector<int> vec;
	vec.clear();
	ll tot=0;
	int res=x-(int)c[1].size();
	for(int i=2;i<=m;++i){
		for(int j=x-1;j<(int)c[i].size();++j){
			tot+=c[i][j];
			--res;
		}
		for(int j=0;j<min((int)c[i].size(),x-1);++j){
			vec.push_back(c[i][j]);
		}
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<res;++i){
		tot+=vec[i];
	}
	return tot;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		c[x].push_back(y);
	}
	for(int i=1;i<=m;++i){
		sort(c[i].begin(),c[i].end(),greater<int>());
	}
	ans=inf;
	for(int i=max((int)c[1].size(),1);i<=n;++i){
		ans=min(ans,Solve(i));
	}
	printf("%lld\n",ans);
	return 0;
}