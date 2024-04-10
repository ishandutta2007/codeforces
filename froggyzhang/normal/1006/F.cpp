#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
#define N 22
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
int n,m,mid;
ll a[N][N],k;
map<ll,int> mp[N];
ll ans;
void dfs1(int x,int y,ll d){
	d^=a[x][y];
	if(x+y==mid){
		++mp[x][d];
		return;
	}
	if(x<n)dfs1(x+1,y,d);
	if(y<m)dfs1(x,y+1,d);
}
void dfs2(int x,int y,ll d){
	if(x+y==mid){
		ans+=mp[x][k^d];
		return;
	}
	d^=a[x][y];
	if(x>1)dfs2(x-1,y,d);
	if(y>1)dfs2(x,y-1,d);
}
int main(){
	n=read(),m=read(),k=read(),mid=(m+n)/2+1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	dfs1(1,1,0);
	dfs2(n,m,0);
	printf("%lld\n",ans);
	return 0;
}