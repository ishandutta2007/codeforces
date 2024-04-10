#include<stdio.h>
#include<algorithm>
int n;
long long int dest;
struct node{
	long long int v;
	long long int c;
	bool operator<(const node&r)const{
		return c<r.c;
	}
};
node a[200100];
long long int dp[200100];
int q[200100];
int qs,qe;
long long int cdp(int x,int p){
	long long int t=((a[p].c-dp[x]+a[x].v-1)/a[x].v);
	return -t*a[p].v+t*a[x].v+dp[x]-a[p].c;
}
long long int crp(int x,int y){
	long long int t=(dp[y]-dp[x])/(a[x].v-a[y].v);
	return t*a[y].v+dp[y];
}
int main(){
	int i,j;
	long long int t,ans;
	scanf("%d%I64d",&n,&dest);
	for(i=0;i<n;i++){
		scanf("%I64d%I64d",&a[i].v,&a[i].c);
	}
	std::sort(a,a+n);
	q[0]=0;
	qs=0;
	qe=1;
	dp[0]=0;
	ans=((dest-dp[0]+a[0].v-1)/a[0].v);
	for(i=1;i<n;i++){
		if(a[q[qe-1]].v<a[i].v){
			while(qs+1<qe&&cdp(q[qs+1],i)>cdp(q[qs],i))qs++;
			dp[i]=cdp(q[qs],i);
			while(qs+1<qe&&crp(q[qe-1],q[qe-2])>=crp(i,q[qe-1])){
				qe--;
			}
			q[qe]=i;
			qe++;
			t=((dest-dp[i]+a[i].v-1)/a[i].v);
			if(ans>t)ans=t;
		}
	}
	printf("%I64d",ans);
}