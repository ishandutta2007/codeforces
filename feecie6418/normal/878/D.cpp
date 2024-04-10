#include<bits/stdc++.h>
using namespace std;
struct Query{
	int x,y,z;
}q[100005];
struct Thing{
	int id,x;
}p[100005][13];
int n,m,Q,a[13][100005],tot,b[100105];
bitset<4105> f[100105];
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=0;i<m;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(int j=1;j<=n;j++){
		for(int i=0;i<m;i++)p[j][i]={i,a[i][j]};
		sort(p[j],p[j]+m,[](Thing x,Thing y){return x.x>y.x;});
	}
	for(int i=1;i<=Q;i++){
		scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].z);
		if(q[i].x!=3)q[i].y--,q[i].z--;
		else q[i].y--;
	}
	for(int i=0;i<(1<<m);i++){
		for(int j=0;j<m;j++)f[j][i]=(i>>j)&1;
	}
	tot=m;
	for(int j=1;j<=Q;j++){
		if(q[j].x==1)f[tot++]=f[q[j].y]|f[q[j].z];
		if(q[j].x==2)f[tot++]=f[q[j].y]&f[q[j].z];
	}
	for(int i=1;i<=Q;i++){
		if(q[i].x!=3)continue;
		for(int j=0,sta=0;j<m;j++){
			sta|=1<<p[q[i].z][j].id;
			if(f[q[i].y][sta]){
				printf("%d\n",p[q[i].z][j].x);
				break;
			}
		}
	}
}