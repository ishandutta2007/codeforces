#include<bits/stdc++.h>
using namespace std;
#define N 600060
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
int n,m,f[N],siz[N][2];
char s[N];
inline int getf(int x){
	return f[x]==x?x:f[x]=getf(f[x]);
}
int ans;
inline void Merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy)return ;
	ans-=min(siz[fx][0],siz[fx][1])+min(siz[fy][0],siz[fy][1]);
	siz[fx][0]+=siz[fy][0];
	siz[fx][1]+=siz[fy][1];
	f[fy]=fx;
	ans+=min(siz[fx][0],siz[fx][1]);
}
array<int,2> d[N];
int main(){
	n=read(),m=read()+1;
	for(int i=1;i<=(m<<1);++i)f[i]=i;
	for(int i=1;i<=m;++i)siz[i][0]=1;
	for(int i=1;i<=m;++i)siz[i+m][1]=1;
	scanf("%s",s+1);
	for(int i=1;i<m;++i){
		int k=read();
		while(k--){
			int x=read();
			if(d[x][0])d[x][1]=i;
			else d[x][0]=i;
		}
	}
	for(int i=1;i<=n;++i){
		int x=get<0>(d[i]);
		int y=get<1>(d[i]);
		if(s[i]=='1'){
			Merge(x,y);
			Merge(x+m,y+m);	
		}
		else{
			Merge(x+m,y);
			Merge(x,y+m);
		}
		int u=getf(0);
		printf("%d\n",(ans>>1)+(siz[u][0]<siz[u][1]?siz[u][1]-siz[u][0]:0));
	}
	return 0;
}