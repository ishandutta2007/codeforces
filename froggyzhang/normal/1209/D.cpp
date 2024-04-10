#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
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
int n,k,ans;
int f[N];
int s[N];
int p[N];
int vis[N];
queue<int> q;
int getf(int x){
	if(f[x]==x)return x;
	return f[x]=getf(f[x]);
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		f[i]=i;
		p[i]=1;
	}
	for(int i=1;i<=k;i++){
		int x=read(),y=read();
		int fx=getf(x),fy=getf(y);
		s[fx]++;
		if(fx==fy)continue;
		s[fx]+=s[fy];
		s[fy]=0;
		p[fx]+=p[fy];
		p[fy]=0;
		f[fy]=fx;
	} 
	for(int i=1;i<=n;i++){
		int fx=getf(i);
		if(vis[fx])continue;
		vis[fx]=1;
		ans+=max(0,s[fx]-p[fx]+1);
	}
	printf("%d\n",ans);
	return 0;
}