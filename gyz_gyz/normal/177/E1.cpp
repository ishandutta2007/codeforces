#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 200000
int n;long long c,a[N],b[N],l,r,m,mm,ss;double x;
int main(){
	scanf("%d%I64d",&n,&c);c-=n;
	rep(i,1,n)scanf("%I64d%I64d",&a[i],&b[i]);
	l=1;r=10000000000000ll;m=(l+r+1)/2;
	rep(i,1,n)ss+=a[i];
	if(!ss){
		if(!c)printf("-1\n");else printf("0\n");return 0;
	}
	while(l<r){x=0;
		rep(i,1,n)x+=a[i]*m/b[i];
		if(x>c)r=m-1;else l=m;m=(l+r+1)/2;
	}mm=m;
	l=1;r=10000000000000ll;m=(l+r)/2;
	while(l<r){x=0;
		rep(i,1,n)x+=a[i]*m/b[i];
		if(x<c)l=m+1;else r=m;m=(l+r)/2;
	}
	x=0;rep(i,1,n)x+=a[i]*m/b[i];
	if((long long)x!=c){printf("0\n");return 0;}
	printf("%I64d\n",mm-m+1);
}