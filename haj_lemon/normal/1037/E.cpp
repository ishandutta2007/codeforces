#include<bits/stdc++.h>
using namespace std;
struct edg{int x,y,an;}v[200010];
struct Info{int nu,ne;bool p;}a[400010];
int m,n,k,d[200010],num=1,li[200010],b[200010],ansn;
bool vi[200010];
void jb(int x,int y){d[y]++;a[++num].nu=y;a[num].ne=b[x];b[x]=num;a[num].p=true;}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	ansn=n;
	for (int i=1;i<=n;i++)vi[i]=true;
	for (int i=1;i<=m;i++){scanf("%d %d",&v[i].x,&v[i].y);jb(v[i].x,v[i].y);jb(v[i].y,v[i].x);}
	int l=1,r=0;
	for (int i=1;i<=n;i++)if (d[i]<k){li[++r]=i;ansn--;vi[i]=false;}
	for (int i=m;i>=1;i--){
		while (l<=r){
			for (int y=b[li[l]];y;y=a[y].ne){
				if (vi[a[y].nu]&&a[y].p){
					d[a[y].nu]--;a[y].p=false;a[y^1].p=false;
					if (d[a[y].nu]<k){ansn--;vi[a[y].nu]=false;li[++r]=a[y].nu;}
				}
			}
			l++;
		}
		v[i].an=ansn;
		if (a[i*2].p&&vi[v[i].x]&&vi[v[i].y]){
			a[i*2].p=false;a[i*2+1].p=false;
			d[v[i].x]--;
			if (d[v[i].x]<k){ansn--;vi[v[i].x]=false;li[++r]=v[i].x;}
			d[v[i].y]--;
			if (d[v[i].y]<k){ansn--;vi[v[i].y]=false;li[++r]=v[i].y;}
		}
	}
	for (int i=1;i<=m;i++) printf("%d\n",v[i].an);
	return 0;
}