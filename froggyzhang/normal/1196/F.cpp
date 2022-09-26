#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
#define N 200020
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
int p[N],n,m,K;
ll dis[808][808];
vector<ll> path;
struct Link{
	int x,y,w;
}l[N];
bool cmp(Link x,Link y){
	return x.w<y.w;
}
int main(){
	read(),m=read(),K=read();
	for(int i=1;i<=m;++i){
		l[i].x=read(),l[i].y=read(),l[i].w=read();
	}
	sort(l+1,l+m+1,cmp);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=K;++i){
		if(!p[l[i].x])p[l[i].x]=++n;
		if(!p[l[i].y])p[l[i].y]=++n;
		dis[p[l[i].x]][p[l[i].y]]=dis[p[l[i].y]][p[l[i].x]]=l[i].w;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(dis[i][j]==inf)continue;
			path.push_back(dis[i][j]);
		}
	}
	sort(path.begin(),path.end());
	//nth_element(path.begin(),path.begin()+K,path.end());
	printf("%lld\n",path[K-1]);
	return 0;
}