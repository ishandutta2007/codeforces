#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int m,n,a[N],b[N],vis[N];
ll ans;
struct Union_Set{
	int f[N];
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx;
	}
}S;
struct node{
	int val,u,x;
	bool operator <(const node b)const{
		return val>b.val;
	}
};
vector<node> qwq;
int main(){
	m=read(),n=read();
	for(int i=1;i<=m;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	for(int i=1;i<=m;++i){
		int k=read();
		while(k--){
			int x=read();
			qwq.push_back({a[i]+b[x],i,x});
			ans+=a[i]+b[x];
		}
	}
	sort(qwq.begin(),qwq.end());
	S.init(n);
	for(auto tmp:qwq){
		if(!vis[tmp.u]){
			vis[tmp.u]=S.getf(tmp.x);
			ans-=tmp.val;
		}
		else{
			if(S.getf(vis[tmp.u])^S.getf(tmp.x)){
				S.Merge(vis[tmp.u],tmp.x);
				ans-=tmp.val;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}