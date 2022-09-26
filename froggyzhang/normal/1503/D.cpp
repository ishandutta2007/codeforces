#include<bits/stdc++.h>
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
int n,a[N],b[N],p[N<<1],t[N<<1],ans,vis[N];
int g[N<<1];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read(),b[i]=read();
		p[a[i]]=p[b[i]]=i;
		g[b[i]]=a[i],g[a[i]]=b[i];
		t[a[i]]=1;
	}
	int l=1,r=(n<<1);
	while(l<=r){
		int c[2]={0,0};
		while(vis[p[l]]&&l<=r)++l;
		if(l>r)break;
		++c[t[l]];
		int now=0,u=l;
		vis[p[l]]=1;
		++l;
		
		while(l<=r){
			if(!now){
				int las=0;
				while(l<=r){	
					if(p[r]==p[u])break;
					if(vis[p[r]]){--r;continue;}
					vis[p[r]]=1;
					++c[t[r]];
					if(g[r]>g[u]||(las&&g[r]<g[las]))return !printf("-1\n");
					las=r;
					--r;
				}
				if(!las)break;
				u=las;
			}
			else{
				int las=0;
				while(l<=r){
					if(p[l]==p[u])break;
					if(vis[p[l]]){++l;continue;}
					vis[p[l]]=1;
					++c[t[l]];
					if(g[l]<g[u]||(las&&g[l]>g[las]))return !printf("-1\n");
					las=l;
					++l;
				}
				if(!las)break;
				u=las;
			}
			now^=1;
		}
		ans+=min(c[0],c[1]);
	}
	printf("%d\n",ans);
	return 0;
}