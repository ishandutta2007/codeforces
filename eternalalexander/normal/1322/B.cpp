#include <bits/stdc++.h>
#define maxn 400005
int n,a[maxn],p1[maxn],p0[maxn],ans;
int get(int x,int p){return (x>>p)&1;}
int calc(int x){
//	printf("calc %d\n",x);
	int t1=0,t0=0,ans=0;
	for(int i=1;i<=n;++i){
		int t=a[i]&((1<<x)-1);
		if(get(a[i],x))p1[++t1]=t;
		else p0[++t0]=t;
	}std::sort(p1+1,p1+t1+1);std::sort(p0+1,p0+t0+1);
//	for(int i=1;i<=t1;++i)printf("%d ",p1[i]);printf("\n");
//	for(int i=1;i<=t0;++i)printf("%d ",p0[i]);printf("\n");
	//0 - 0
	int p=1;
	for(int i=t0;i>=1;--i){
		while(p<i&&p0[p]+p0[i]<(1<<x))p++;
		if(p>=i)break;
	//	printf("%d %d\n",p,i);
		ans=(ans+(i-p))%2;
	}//1 - 1
	p=1;
	for(int i=t1;i>=1;--i){
		while(p<i&&p1[p]+p1[i]<(1<<x))p++;
		if(p>=i)break;
		ans=(ans+(i-p))%2;
	}//1 - 0
	p=t0;
	for(int i=1;i<=t1;++i){
		while(p>0&&p1[i]+p0[p]>=(1<<x))p--;
		ans=(ans+p)%2;
	}//printf("=%d\n",ans);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=0;i<31;++i){
		ans=ans+calc(i)*(1<<i);
	}
	printf("%d",ans);
	return 0;
}