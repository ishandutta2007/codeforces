#include<bits/stdc++.h>
using namespace std;
int n,K,m,a[55],v[55][55],fa[55],d[55],on[10005],ans=0,fin=1e9;
struct E{
	int x,y,z;
}e[10005];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
int Judge(){
	int u=0;
	for(int i=1;i<=K;i++)u+=max(d[i]-a[i],0);
	return u;
}
void Try(){
	for(int i=1;i<=n;i++)fa[i]=i,d[i]=0;
	for(int i=1;i<=m;i++)on[i]=0;
	ans=0;
	for(int i=1;i<=m;i++){
		int u=gf(e[i].x),v=gf(e[i].y);
		if(u==v)continue;
		ans+=e[i].z,d[e[i].x]++,d[e[i].y]++;
		fa[u]=v,on[i]=1;
	}
	int sum=0,ff=0;
	while(sum=Judge()){
		int mx=0,mxid=0;
		while(!mx){
			for(int i=m;i>=1;i--){
				if(on[i]&&(d[e[i].x]>a[e[i].x]||d[e[i].y]>a[e[i].y]))
					if(rand()%4){mx=e[i].z,mxid=i;break;}
			}
		}
		d[e[mxid].x]--;
		d[e[mxid].y]--;
		ans-=mx;
		on[mxid]=0;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++)if(on[i])fa[gf(e[i].x)]=gf(e[i].y);
		int mxj=0;
		for(int i=1;i<=m;i++)
			if(!on[i]&&gf(e[i].x)!=gf(e[i].y)&&i!=mxid){
				d[e[i].x]++,d[e[i].y]++;
				if(sum-Judge()>mxj)mxj=sum-Judge();
				d[e[i].x]--,d[e[i].y]--;
			}
		int flag=0;
		while(!flag){
			for(int i=1;i<=m;i++){
				if(!on[i]&&gf(e[i].x)!=gf(e[i].y)&&i!=mxid){
					d[e[i].x]++,d[e[i].y]++;
					if(sum-Judge()>0||!mxj){
						if(rand()%4){
							on[i]=1,ans+=e[i].z,flag=1;
							break;
						}
					}
					if(ff){
						if(sum-Judge()>=0){
							if(rand()%4==0){
								on[i]=1,ans+=e[i].z,flag=1;
								break;
							}
						}
					}
					d[e[i].x]--,d[e[i].y]--;
				}
			}
		}
		ff^=1;
	}
	fin=min(fin,ans);
}
int main(){
	cin>>n>>K,srand(time(0));
	for(int i=1;i<=n;i++)fa[i]=i,a[i]=1e9,d[i]=0;
	for(int i=1;i<=K;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)cin>>v[i][j],e[++m]={i,j,v[i][j]};
	sort(e+1,e+m+1,[](E x,E y){return x.z!=y.z?x.z<y.z:min(x.x,x.y)>min(y.x,y.y);});
	int st=clock();
	do Try(); while(1.0*(clock()-st)/CLOCKS_PER_SEC<5.5);
	cout<<fin<<'\n';
}