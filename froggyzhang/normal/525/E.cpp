#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0,f=1;
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
int n,k,a[233],mid;
ll S,fac[233],ans;
map<ll,int> mp[233];
void dfs1(int u,int use,ll num){
	if(num>S)return;
	if(u==mid){
		++mp[use][num];
		return;
	}
	if(use<k&&a[u]<=19){
		dfs1(u+1,use+1,num+fac[a[u]]);
	}
	dfs1(u+1,use,num+a[u]);
	dfs1(u+1,use,num);
}
void dfs2(int u,int use,ll num){
	if(num>S)return;
	if(u==mid-1){
		for(int i=0;i<=k-use;++i){
			if(mp[i].count(S-num))ans+=mp[i][S-num];
		}
		return;
	}
	if(use<k&&a[u]<=19){
		dfs2(u-1,use+1,num+fac[a[u]]);
	}
	dfs2(u-1,use,num+a[u]);
	dfs2(u-1,use,num);
}
int main(){
	n=read(),k=read();
	S=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	fac[0]=1;
	for(int i=1;i<=19;++i){
		fac[i]=fac[i-1]*i;
	}
	mid=((n+1)>>1);
	dfs1(1,0,0);
	dfs2(n,0,0);
	printf("%I64d\n",ans);
	return 0;
}