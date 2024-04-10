#include<bits/stdc++.h>
using namespace std;
#define N 105
const int inf=0x3f3f3f3f;
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
int n,m,f[1<<14][N],g[1<<14][N],ans,df[1<<14][20],dg[1<<14][N];
struct Point{
	int x,y,t;
	friend bool operator < (const Point &a,const Point &b){
		return a.t<b.t;
	}
}a[N],b[N];
inline int Dis(Point a,Point b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int main(){
	n=read(),m=read();
	for(int i=0;i<n;++i){
		a[i].x=read(),a[i].y=read();
	}
	for(int i=1;i<=m;++i){
		b[i].x=read(),b[i].y=read();
		b[i].t=read();
	}
	sort(b+1,b+m+1);
	for(int i=0;i<(1<<n);++i){
		for(int j=0;j<n;++j){
			df[i][j]=inf;
			for(int k=0;k<n;++k){
				if(i>>k&1){
					df[i][j]=min(df[i][j],Dis(a[j],a[k]));
				}
			}	
		}
		for(int j=1;j<=m;++j){
			dg[i][j]=inf;
			for(int k=0;k<n;++k){
				if(i>>k&1){
					dg[i][j]=min(dg[i][j],Dis(b[j],a[k]));
				}
			}
		}
	}
	memset(f,0x3f,sizeof(f));
	memset(g,-1,sizeof(g));
	for(int i=0;i<n;++i){
		f[1<<i][0]=0;
	}
	for(int i=1;i<=m;++i){
		g[0][i]=1;
	}
	for(int s=0;s<(1<<n);++s){
		for(int i=0;i<=m;++i){
			for(int j=1;j<=m;++j){
				if(f[s][i]+dg[s][j]<=b[j].t)g[s][j]=max(g[s][j],i+1);		
			}
		}
		for(int i=1;i<=m;++i){
			if(!~g[s][i])continue;
			for(int j=i+1;j<=m;++j){
				if(min(dg[s][j],Dis(b[i],b[j]))+b[i].t<=b[j].t)g[s][j]=max(g[s][j],g[s][i]+1);		
			}
		}
		for(int i=1;i<=m;++i){
			if(~g[s][i])f[s][g[s][i]]=min(f[s][g[s][i]],b[i].t);
		}
		for(int i=0;i<=m;++i){
			for(int j=0;j<n;++j){
				if(!(s>>j&1))f[s|(1<<j)][i]=min(f[s|(1<<j)][i],f[s][i]+df[s][j]);
			}	
		}
		for(int i=1;i<=m;++i){
			for(int j=0;j<n;++j){
				if(!(s>>j&1)&&~g[s][i]){
					f[s|(1<<j)][g[s][i]]=min(f[s|(1<<j)][g[s][i]],b[i].t+Dis(b[i],a[j]));
				}	
			}
		}
	}
	for(int s=0;s<(1<<n);++s){
		for(int i=1;i<=m;++i){
			ans=max(ans,g[s][i]);
			if(f[s][i]<inf)ans=max(ans,i);		
		}
	}
	printf("%d\n",ans);
	return 0;
}