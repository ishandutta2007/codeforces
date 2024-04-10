#include<stdio.h>
#include<algorithm>
int d,n,m;
int deq[200100];
int qs,qe;
struct stt{
	int x,p;
	bool operator<(const stt&r)const{
		return x<r.x;
	}
};
stt a[200100];
int main(){
	int i,j;
	long long int ans;
	scanf("%d%d%d",&d,&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a[i].x,&a[i].p);
	}
	a[m].x=0;
	a[m].p=0;
	m++;
	a[m].x=d;
	a[m].p=0;
	m++;
	std::sort(a,a+m);
	for(i=1;i<m;i++){
		if(a[i].x>a[i-1].x+n){
			printf("-1");
			return 0;
		}
	}
	qs=0;
	qe=0;
	j=0;
	ans=0;
	for(i=0;i<m;i++){
		while(qs<qe&&a[deq[qs]].x+n<a[i].x){
			ans+=((long long int)a[deq[qs]].x+n-j)*a[deq[qs]].p;
			j=a[deq[qs]].x+n;
			qs++;
		}
		ans+=((long long int)a[i].x-j)*a[deq[qs]].p;
		j=a[i].x;
		while(qs<qe&&a[deq[qe-1]].p>a[i].p){
			qe--;
		}
		deq[qe]=i;
		qe++;
	}
	printf("%I64d",ans);
	return 0;
}