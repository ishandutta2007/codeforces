#include<stdio.h>
#include<algorithm>
int n,m;
struct dot{
	int x,y;
	bool operator<(const dot&r)const{
		return x<r.x;
	}
};
struct segq{
	int x,ya,yb,c;
	bool operator<(const segq&r)const{
		return x<r.x;
	}
};
dot a[100100];
segq b[200100];
int px[100100];
long long int ans[100100];
long long int rans[100100];
int lup[100100];
int pd[31000000];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	std::sort(a,a+n);
	px[0]=0;
	for(i=1;i<n;i++){
		if(a[i].x-a[i-1].x>m){
			px[i]=px[i-1]+m;
		}
		else{
			px[i]=px[i-1]+a[i].x-a[i-1].x;
		}
	}
	for(i=0;i<n;i++){
		a[i].x=px[i];
		b[i*2].x=a[i].y;
		b[i*2].ya=a[i].x;
		b[i*2].yb=a[i].x+m;
		b[i*2].c=1;
		b[i*2+1].x=a[i].y+m;
		b[i*2+1].ya=a[i].x;
		b[i*2+1].yb=a[i].x+m;
		b[i*2+1].c=-1;
	}
	std::sort(b,b+2*n);
	for(i=0;i<2*n;i++){
		for(j=b[i].ya;j<b[i].yb;j++){
			if(pd[j]!=0){
				ans[pd[j]]+=(b[i].x-lup[pd[j]])*rans[pd[j]];
				lup[pd[j]]=b[i].x;
			}
			rans[pd[j]]--;
			pd[j]+=b[i].c;
			if(pd[j]!=0){
				ans[pd[j]]+=(b[i].x-lup[pd[j]])*rans[pd[j]];
				lup[pd[j]]=b[i].x;
			}
			rans[pd[j]]++;
		}
	}
	for(i=1;i<=n;i++){
		printf("%I64d ",ans[i]);
	}
}