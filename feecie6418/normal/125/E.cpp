#include <bits/stdc++.h>
using namespace std;
double M;
struct E{
	int x,y,z,tp,id;//01 
	bool operator <(const E yy) const {
		double p1=tp?z:z+M,p2=yy.tp?yy.z:yy.z+M;
		return p1<p2; 
	}
}e[100005];
int n,m,k,fa[50005],p[50005],d[50005];
int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
int Calc(double mid,int r){
	for(int i=1;i<=n;i++)fa[i]=i;
	M=mid,sort(e+1,e+m+1);
	int ans[2]={0},w=n-1;
	for(int i=1;i<=m;i++){
		int fx=gf(e[i].x),fy=gf(e[i].y);
		if(fx==fy)continue;
		ans[1]+=e[i].z,ans[0]+=!e[i].tp;
		if(r&&ans[0]>k){
			ans[1]-=e[i].z,ans[0]-=!e[i].tp;
			continue;
		}
		fa[fx]=fy,w--;
		if(r)p[++p[0]]=e[i].id;
	}
	if(w)puts("-1"),exit(0);
	return ans[r];
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),e[i]={x,y,z,!(x==1||y==1),i},d[x]++,d[y]++;
	if(d[1]<k||(n>1&&!k))return puts("-1"),0;
	double l=-100001,r=100001,ans=0;
	while(r-l>1e-8){
		double mid=(l+r)/2;
		int w=Calc(mid,0);
		if(w==k){
			ans=mid;
			break;
		}
		if(r-l<0.1&&w>k){
			ans=mid;
			break;
		}
		if(w<k)r=mid;
		else ans=mid,l=mid;
	}
	Calc(ans,1);
	printf("%d\n",n-1);
	while(p[0])printf("%d ",p[p[0]--]);
	return 0;
}//