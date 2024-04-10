#include<stdio.h>
#include<queue>
int n,m,v;
long long int p;
long long int h[100100];
long long int a[100100];
long long int c[100100];
long long int rday[100100];
struct node{
	int loc;
	bool operator<(const node&r)const{
		return rday[loc]<rday[r.loc];
	}
};
std::priority_queue<node> pq;
bool psrc(long long int x){
	int i,j,k;
	node w;
	while(pq.size()!=0)pq.pop();
	for(i=0;i<n;i++){
		c[i]=x-m*a[i];
		rday[i]=-2;
		if(c[i]<h[i])rday[i]=-1;
		if(c[i]<0){
			rday[i]=(-c[i]-1)/a[i];
		}
		w.loc=i;
		pq.push(w);
	}
	for(i=m-1;i>=0;i--){
		for(j=0;j<v;j++){
			w=pq.top();
			k=w.loc;
			pq.pop();
			if(rday[k]>=i)return 0;
			c[k]+=p;
			if(c[k]<0){
				rday[k]=(-c[k]-1)/a[k];
			}
			else if(c[k]<h[k]){
				rday[k]=-1;
			}
			else{
				rday[k]=-2;
			}
			pq.push(w);
		}
	}
	for(i=0;i<n;i++){
		if(c[i]<h[i])return 0;
	}
	return 1;
}
int main(){
	int i;
	long long int ans,j;
	scanf("%d%d%d%I64d",&n,&m,&v,&p);
	for(i=0;i<n;i++){
		scanf("%d%d",&h[i],&a[i]);
	}
	ans=-1;
	for(j=45;j>=0;j--){
		ans+=(1LL<<j);
		if(psrc(ans))ans-=(1LL<<j);
	}
	ans++;
	printf("%I64d",ans);
}