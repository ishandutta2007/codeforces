#include<bits/stdc++.h>
using namespace std;
inline int Rd(){
	int s=0;char fl=0,c=getchar();
	while(c<'0'||c>'9')fl|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return fl?-s:s;
}
const int N=5005,M=1e5+5;
struct node{
	int x,y,id,c;double z;
	bool operator <(const node &u)const{
		return z<u.z;
	}
}a[M],d[M];
int n,m,k,num,tot,fa[N],bj=0;
char vit[M];
double ans;
int Getf(int x){return x==fa[x]?x:fa[x]=Getf(fa[x]);}
inline int Solve(double val){
	for(int i=1;i<=n;i++)fa[i]=i;
	ans=num=tot=0;
	for(int i=1;i<=m;i++){
		d[i]=a[i];vit[i]=0;
		if(d[i].c)d[i].z+=val;
	}
	sort(d+1,d+m+1);
	for(int i=1;i<=m;i++){
		int x=Getf(d[i].x),y=Getf(d[i].y);
		if(x==y)continue;
		fa[y]=x;tot++,ans+=d[i].z;
		if(d[i].c)num++;vit[d[i].id]=1;
		if(tot==n-1)break;
	}
	if(num==k)bj=1;
	return num>=k;
}
int main(){
	n=Rd(),m=Rd(),k=Rd();
	for(int i=1;i<=m;i++){
		a[i].x=Rd(),a[i].y=Rd(),a[i].z=Rd(),a[i].id=i;
		a[i].c=(a[i].x==1||a[i].y==1);
	}
	double l=-10000,r=10000,op;
	for(int i=1;i<=100;i++){
		double mid=(l+r)/2;
		if(Solve(mid))l=mid;
		else r=mid;
	}
	Solve(l);
	if(tot<n-1||bj==0)return printf("-1\n"),0;
	printf("%d\n",n-1);
	for(int i=1;i<=m;i++)if(vit[i])printf("%d ",i);
	return 0;
}