#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define db double
int f[N],f1[N],f2[N],f3[N],ee,ans;
inline int find(int x){if(f[x]==x)return x;f[x]=find(f[x]);return f[x];}
vector<db>dis[N],dis_[N];
vector<int>son[N];
void dfs(int now,int fat){
	f2[now]=-1e9;
	f1[now]=0;
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			dfs(T,now);
			if(f1[T]>=f1[now])f2[now]=f1[now],f1[now]=f1[T]+1;
			else f2[now]=max(f2[now],f1[T]+1);
		}
	}
}
void dfs_(int now,int fat){
	ans=max(ans,f3[now]+f1[now]);
	++dis[ee][max(f3[now],f1[now])];
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			if(f1[T]+1==f1[now]){
				f3[T]=max(f3[now]+1,f2[now]+1);
			}
			else f3[T]=max(f3[now]+1,f1[now]+1);
			dfs_(T,now);
		}
	}
}
map<pair<int,int>,db>p;
int n,m,q,i,j,mx[N],MX,c[N],x,y; 
db Ans,dd;
int main(){
//	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	for(i=1;i<=n;++i)f[i]=i,c[i]=1;
	for(i=1;i<=m;++i)cin>>x>>y,son[x].push_back(y),son[y].push_back(x),c[find(y)]+=c[find(x)],f[find(x)]=find(y);
	for(i=1;i<=n;++i)if(find(i)==i){
		for(j=0;j<c[i];++j)dis[i].push_back(0),dis_[i].push_back(0);
		ee=i;ans=0;dfs(i,0);dfs_(i,0);mx[i]=ans;
		for(j=0;j<c[i];++j)dis[i][j]/=c[i];
		for(j=c[i]-2;~j;--j)dis[i][j]+=dis[i][j+1];
		for(j=0;j<c[i];++j)dis_[i][j]=dis[i][j];
		for(j=c[i]-2;~j;--j)dis_[i][j]+=dis_[i][j+1];
		if(i==2||i==3||i==4){
			
//			for(j=0;j<c[i];++j)cout<<dis[i][j]<<" "<<dis_[i][j]<<"\n";
		}
	}
	while(q--){
		cin>>x>>y;
		x=find(x);y=find(y);
		if(x==y){printf("-1\n");continue;}
		if(p[make_pair(x,y)]>0.00000001){printf("%.10lf\n",p[make_pair(x,y)]);continue;}
		if(c[x]<=c[y]){
			swap(x,y);
		}
		Ans=0;MX=max(mx[x],mx[y]);
//		cout<<MX<<"\n";
		for(i=0;i<=mx[y];++i){
			dd=dis[y][i];
			if(i!=mx[y])dd-=dis[y][i+1]; 
//			cout<<i<<"\n"<<dis[y][i]<<" "<<dis_[x][MX-i]<<"\n";
			if(i==MX)Ans+=dd*(MX+dis_[x][0]);
			else Ans+=dd*(MX+dis_[x][MX-i]);
		}
		if(c[x]>=300&&c[y]>=300)p[make_pair(x,y)]=p[make_pair(y,x)]=Ans;
		printf("%.10lf\n",Ans);
	}
}