#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<assert.h>
using namespace std;
#define N 5555
inline int read(){
	int x=0,f=1;
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
int T,n,m,vis[N],ans[N],mx;
vector<int> vec[N];
int Solve(int l,int r){
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	int tot=0;
	for(int i=l;i<=mid;++i)tot+=vec[i].size();
	cout<<"? "<<tot;
	for(int i=l;i<=mid;++i){
		for(auto x:vec[i]){
			cout<<" "<<x;
		}
	}
	cout<<endl;
	int p=read();
	assert(~p);
	if(p==mx)return Solve(l,mid);
	return Solve(mid+1,r);
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		mx=0;
		for(int i=1;i<=m;++i){
			vec[i].clear();
			int c=read();
			while(c--){
				vec[i].push_back(read());
			}
		}
		cout<<"? "<<n;
		for(int i=1;i<=n;++i)vis[i]=0,cout<<" "<<i;
		cout<<endl;
		mx=read();
		int x=Solve(1,m);
		for(int i=1;i<=m;++i)ans[i]=mx;
		if(~x){
			cout<<"? "<<n-vec[x].size();
			for(auto gu:vec[x])vis[gu]=1;
			for(int i=1;i<=n;++i)if(!vis[i])cout<<" "<<i;
			cout<<endl;
			ans[x]=read();
			assert(~ans[x]);
		}
		cout<<"! ";
		for(int i=1;i<=m;++i){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		string s;
		cin>>s;
		assert(s[0]=='C');
	}
	return 0;
}