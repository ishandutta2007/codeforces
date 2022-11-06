#include<bits/stdc++.h>
using namespace std;
const int Mxdt=100000;const long long INF=1e16;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
char pc(char c,bool opt){
	return (opt||putchar(c)),0;static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (opt||(*p1=++c,p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10^48,0);
}
void printnum(int x,char c){
	if(x<0)pc('-',0),x=-x;
	print(x);pc(c,0);
}
int n,m,Q,x,y,w,X[360005],Y[360005],W[360005],opt[360005],vis[605],ans;long long a[605][605],d[605];
struct node{int x,v;};vector<node>v[605];
struct path{
	int x;long long v;
	bool operator<(const path&a)const{return v<a.v;}
};
priority_queue<path>q;
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=INF;
		}
		a[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		x=read();y=read();w=read();
		X[i]=x;Y[i]=y;W[i]=w;
		a[x][y]=a[y][x]=w;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	Q=read();
	for(int i=1;i<=Q;++i){
		x=read();y=read();w=read();
		v[x].push_back((node){y,w});
		v[y].push_back((node){x,w});
	}
	for(int i=1;i<=n;++i){
		if(v[i].size()){
			for(int j=1;j<=n;++j)d[j]=-INF,vis[j]=0;
			for(int j=0;j<v[i].size();++j){
				d[v[i][j].x]=v[i][j].v;
				q.push((path){v[i][j].x,v[i][j].v});
			}
			while(!q.empty()){
				int x=q.top().x;q.pop();
				if(vis[x])continue;vis[x]=1;
				for(int y=1;y<=n;++y){
					if(a[x][y]<INF){
						if(d[y]<d[x]-a[x][y]){
							d[y]=d[x]-a[x][y];
							q.push((path){y,d[y]});
						}
					}
				}
			}
			for(int j=1;j<=m;++j){
				if(a[i][X[j]]+W[j]<=d[Y[j]]){
					opt[j]=1;
				}
			}	
		}
	}
	for(int i=1;i<=m;++i){
		if(opt[i])++ans;
	}
	cout<<ans<<'\n';
	return pc(0,1);
}