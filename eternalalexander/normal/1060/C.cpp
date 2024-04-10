#include <bits/stdc++.h>
#define maxn 2005
int n,m,a[maxn],b[maxn],ans=0,max=0,x;
struct node {
	int len,sum;
}A[maxn*maxn],B[maxn*maxn];
int cmp(node a,node b){return a.sum<b.sum;}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]+=a[i-1];
	for(int i=1;i<=m;++i)scanf("%d",&b[i]),b[i]+=b[i-1];
	scanf("%d",&x);
	int t1=0,t2=0;
	
	for(int i=1;i<=n;++i)
	for(int j=i;j<=n;++j){
		A[++t1].len=j-i+1;
		A[t1].sum=a[j]-a[i-1];
	}std::sort(A+1,A+t1+1,cmp);
	
	for(int i=1;i<=m;++i)
	for(int j=i;j<=m;++j){
		B[++t2].len=j-i+1;
		B[t2].sum=b[j]-b[i-1];
	}std::sort(B+1,B+t2+1,cmp);
	std::reverse(A+1,A+t1+1);
	int p1=0;
	for(int i=1;i<=t1;++i){
		while (p1<t2&&B[p1+1].sum<=x/A[i].sum){p1++;max=std::max(max,B[p1].len);}
		ans=std::max(ans,max*A[i].len);
	}printf("%d",ans);
	return 0;
}