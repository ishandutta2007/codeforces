#include<bits/stdc++.h>
using namespace std;
#define N 5005
const int mod=1e9+7;
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
int n,m,L[N],R[N];
int a[N],c[N],h[N];
vector<int> g[N];
pair<int,int> ans;
pair<int,int> calc(int z){
	bool ok=(z==0);
	pair<int,int> mx=make_pair(0,1);
	static pair<int,int> cnt[N];
	for(int i=1;i<=n;++i)cnt[i].first=cnt[i].second=0;
	for(int i=1;i<=m;++i){
		if(L[i]==z){
			++mx.first;
			ok=true;continue;
		}
		if(c[i]==a[z]){
			if(R[i]>z)++cnt[c[i]].first;
		}
		else{
			if(L[i]<=z&&R[i]>z)++cnt[c[i]].second;
			else if(L[i]<=z||R[i]>z)++cnt[c[i]].first;
		}
	}
	if(!ok)return make_pair(-1,0);
	for(int i=1;i<=n;++i){
		int x=cnt[i].first,y=cnt[i].second;
		if(!x&&!y)continue;
		if(x+y>=2&&y){
			mx.first+=2;
			mx.second=1LL*mx.second*((1LL*x*y+1LL*y*(y-1))%mod)%mod;
		}
		else{
			++mx.first;
			mx.second=1LL*mx.second*(!y?x:2)%mod;		
		}
	}
	return mx;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		g[a[i]].push_back(i);
	}
	for(int i=1;i<=m;++i){
		c[i]=read(),h[i]=read();
		L[i]=(h[i]>(int)g[c[i]].size()?n+1:g[c[i]][h[i]-1]);
		R[i]=(h[i]>(int)g[c[i]].size()?-1:g[c[i]][(int)g[c[i]].size()-h[i]]);
	}
	ans=make_pair(0,0);
	for(int i=0;i<=n;++i){
		pair<int,int> t=calc(i);
		if(t.first>ans.first)ans=t;
		else if(t.first==ans.first)ans.second=(ans.second+t.second)%mod;	
	}
	printf("%d %d\n",ans.first,ans.second);
	return 0;
}