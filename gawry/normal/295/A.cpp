#include<cstdio>
#include<cstring>
#define POWER (1<<17)
long long s[2*POWER];
void increase(int from,int to,long long delta=1){
	from+=POWER;
	to+=POWER;
	s[from]+=delta;
	if(from<to)s[to]+=delta;
	while(from+1<to){
		if(from%2==0)s[from+1]+=delta;
		if(to%2)s[to-1]+=delta;
		from/=2;
		to/=2;
	}
}
void clear(){
	for(int i=1;i<POWER;i++){
		s[2*i]+=s[i];
		s[2*i+1]+=s[i];
	}
}
int a[POWER],l[POWER],r[POWER],d[POWER],x[POWER],y[POWER];
long long f[POWER];
main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++)scanf("%d %d %d",&l[i],&r[i],&d[i]);
	for(int i=0;i<k;i++)scanf("%d %d",&x[i],&y[i]);
	memset(s,0,sizeof(s));
	for(int i=0;i<k;i++){
		increase(x[i],y[i]);
	}
	clear();
  for(int i=0;i<m;i++){
		f[i]=s[POWER+1+i]*d[i];
	}
	memset(s,0,sizeof(s));
	for(int i=0;i<m;i++){
		increase(l[i],r[i],f[i]);
	}
	clear();
	for(int i=0;i<n;i++)printf("%I64d ",a[i]+s[POWER+1+i]);
	puts("");
}