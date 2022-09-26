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
int n,m,d[N],k;
map<string,int> id;
vector<int> G[N];
vector<int> ans;
string s;
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i){
		cin>>s;
		id[s]=i;
	}
	for(int i=1;i<=m;++i){
		cin>>s;
		int u=read();
		bool ok=false;
		for(int j=0;j<(1<<k);++j){
			string t=s;
			for(int p=0;p<k;++p){
				if(j>>p&1)t[p]='_';
			}
			if(id.count(t)){
				int v=id[t];
				if(u==v){
					ok=true;continue;
				}
				G[u].push_back(v),++d[v];
			}
		}
		if(!ok)return !printf("NO\n");
	}
	queue<int> q;
	for(int i=1;i<=n;++i){
		if(!d[i])q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ans.push_back(u);
		for(auto v:G[u]){
			if(!--d[v])q.push(v);
		}
	}
	if(ans.size()!=n)return !printf("NO\n");
	printf("YES\n");
	for(auto x:ans)printf("%d ",x);
	return 0;
}