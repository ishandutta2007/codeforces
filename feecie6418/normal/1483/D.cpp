
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dis[605][605],p[605][605];
vector<short> t[360005];
int n,m,g[605][605],u[360005],v[360005],w[360005],is[605][605],ans=0,q,A,B;
int pos(int x,int y){
	return (x-1)*n+y;
}
char buf[2000005];
int p1=2000000;
int gc(){
	//if(p1>=2000000)fread(buf,1,2000000,stdin),p1=0;
	//return buf[p1++];
	return getchar();
}
int rd(){
	int x=0,ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))x=x*10+ch-'0',ch=gc();
	return x;
}
int main(){
	memset(dis,0x3f,sizeof(dis));
//	n=600,m=600;
	n=rd(),m=rd();
 	for(int i=1,x,y,z;i<=m;i++){
 		x=rd(),y=rd(),z=rd();
 		g[x][y]=g[y][x]=z,dis[x][y]=dis[y][x]=z;
 	}
  //  for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)g[i][j]=g[j][i]=dis[i][j]=dis[j][i]=rand()%1000+1;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	q=rd();
	for(int i=1;i<=q;i++)u[i]=rd(),v[i]=rd(),w[i]=rd();
	//for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)u[++q]=i,v[q]=j,w[q]=1e9;
	for(int i=1;i<=q;i++){
		for(int j=1,o;j<=n;j++){
			//cout<<i<<' '<<j<<endl;
			//A=v[i],B=j,o=pos(v[i],j);
			p[v[i]][j]=max(p[v[i]][j],w[i]-dis[u[i]][j]);
			//while(p1+1<t[o].size()&&dis[A][t[o][p1+1]]+g[B][t[o][p1+1]]<=w[i]-dis[u[i]][j])p1++;
			//p[v[i]][j]=max(p[v[i]][j],p1);
			//cout<<w[i]-dis[u[i]][j]<<' '<<v[i]<<' '<<j<<' '<<p1<<endl;
			//cout<<i<<' '<<j<<' '<<p1<<' '<<t[o].size()<<endl;
			//A=u[i],B=j,o=pos(u[i],j);
			//int p2=lower_bound(t[pos(u[i],j)].begin(),t[pos(u[i],j)].end(),w[i]-dis[v[i]][j],[](short x,short y){return dis[A][x]+g[B][x]<=y;})-t[pos(u[i],j)].begin();
			//int p2=p[u[i]][j];
			//while(p2+1<t[o].size()&&dis[A][t[o][p2+1]]+g[B][t[o][p2+1]]<=w[i]-dis[v[i]][j])p2++;
			//p[u[i]][j]=max(p[u[i]][j],p2);
			//cout<<i<<' '<<j<<' '<<p2<<' '<<t[o].size()<<endl;
			p[u[i]][j]=max(p[u[i]][j],w[i]-dis[v[i]][j]);
		}
		//if(i%600==0)cout<<i<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(!g[j][k]||dis[i][k]>1e9)continue;
				if(p[i][j]>=dis[i][k]+g[j][k])is[j][k]=1;
			}
		//	A=i,B=j;
		//	sort(t[pos(i,j)].begin(),t[pos(i,j)].end(),[](short x,short y){return dis[A][x]+g[B][x]<dis[A][y]+g[B][y];});
		}
		//cout<<i<<endl;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(is[i][j])ans++;
	cout<<ans;
}