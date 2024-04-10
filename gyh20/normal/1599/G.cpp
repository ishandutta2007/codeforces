#include<bits/stdc++.h>
#define re register
#define double long double
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,a[200002],b[200002],pos;
struct node{
	int x,y,id;
	bool operator <(const node A)const{return x==A.x?y<A.y:x<A.x;}
}p[200002];
vector<node>A;
inline bool cmp(re int x,re int y,re int z){
	if(a[x]==a[y]&&b[x]==b[y])return 1;
	if(a[x]==a[z]&&b[x]==b[z])return 1;
	if(a[z]==a[y]&&b[z]==b[y])return 1;
	if((a[x]==a[y]&&a[x]==a[z])||((a[x]^a[y])&&(a[x]^a[z])&&(b[y]-b[x])*(a[z]-a[x])==(b[z]-b[x])*(a[y]-a[x])))return 1;
	return 0;
}
inline double dis(node x,node y){
	return sqrt(1ll*(y.x-x.x)*(y.x-x.x)+1ll*(y.y-x.y)*(y.y-x.y));
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read()+2e6,b[i]=read()+2e6,p[i].x=a[i],p[i].y=b[i],p[i].id=i;
	re int px=1,py=2;
	for(re int i=1;i<=min(n,5);++i)
		for(re int j=i+1;j<=min(n,5);++j)
			for(re int k=j+1;k<=min(n,5);++k)
				if(cmp(i,j,k))
					px=i,py=j;
	A.push_back(p[px]),A.push_back(p[py]);
	for(re int i=1;i<=n;++i)if((i^px)&&(i^py)&&A.size()!=n-1&&cmp(px,py,i))A.push_back(p[i]);else pos=i;
	sort(A.begin(),A.end());
	if(p[pos].id==m){
		printf("%.10Lf",dis(A[0],A[A.size()-1])+min(dis(p[pos],A[0]),dis(p[pos],A[A.size()-1])));
		return 0;
	}
	double ans=1e20;
	for(re int i=0;i<A.size();++i){
		re double ss=min(dis(p[m],A[0])+dis(A[0],A[i])+dis(A[i],p[pos]),dis(p[m],A[i])+dis(A[i],A[0])+dis(A[0],p[pos]));
		if(i+1!=A.size())ss+=min(dis(p[pos],A[A.size()-1]),dis(p[pos],A[i+1]))+dis(A[i+1],A[A.size()-1]);
		ans=min(ans,ss);
		ss=min(dis(p[m],A[i])+dis(A[i],A[A.size()-1])+dis(A[A.size()-1],p[pos]),dis(p[m],A[A.size()-1])+dis(A[i],A[A.size()-1])+dis(A[i],p[pos]));
		if(i)ss+=min(dis(p[pos],A[0]),dis(p[pos],A[i-1]))+dis(A[i-1],A[0]);
		ans=min(ans,ss);
	}
	printf("%.10Lf",ans);
}