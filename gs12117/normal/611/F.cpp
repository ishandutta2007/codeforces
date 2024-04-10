#include<stdio.h>
long long int n,a,b;
char s[501000];
long long int mod=1000000007;
long long int p;
long long int d[500100];
long long int ans;
int main(){
	long long int i,j;
	long long int x,y;
	long long int xmax,xmin,ymax,ymin;
	scanf("%I64d%I64d%I64d",&n,&a,&b);
	scanf("%s",s);
	x=0;
	y=0;
	xmin=0;
	ymin=0;
	xmax=a-1;
	ymax=b-1;
	ans=0;
	for(i=0;i<n;i++){
		if(s[i]=='R')y++;
		if(s[i]=='L')y--;
		if(s[i]=='U')x--;
		if(s[i]=='D')x++;
		if(xmax+x>=a){
			ans+=(ymax+1-ymin)*(i+1);
			ans%=mod;
			xmax--;
		}
		if(xmin+x<0){
			ans+=(ymax+1-ymin)*(i+1);
			ans%=mod;
			xmin++;
		}
		if(ymax+y>=b){
			ans+=(xmax+1-xmin)*(i+1);
			ans%=mod;
			ymax--;
		}
		if(ymin+y<0){
			ans+=(xmax+1-xmin)*(i+1);
			ans%=mod;
			ymin++;
		}
		if(xmax<xmin||ymax<ymin){
			printf("%I64d",ans%mod);
			return 0;
		}
	}
	p=0;
	for(i=0;i<n;i++){
		if(s[i]=='R')y++;
		if(s[i]=='L')y--;
		if(s[i]=='U')x--;
		if(s[i]=='D')x++;
		if(xmax+x>=a){
			ans+=(ymax+1-ymin)*(n+i+1);
			ans%=mod;
			xmax--;
			d[p]=i;
			p++;
		}
		if(xmin+x<0){
			ans+=(ymax+1-ymin)*(n+i+1);
			ans%=mod;
			xmin++;
			d[p]=i;
			p++;
		}
		if(ymax+y>=b){
			ans+=(xmax+1-xmin)*(n+i+1);
			ans%=mod;
			ymax--;
			d[p]=i;
			p++;
		}
		if(ymin+y<0){
			ans+=(xmax+1-xmin)*(n+i+1);
			ans%=mod;
			ymin++;
			d[p]=i;
			p++;
		}
		if(xmax<xmin||ymax<ymin){
			printf("%I64d",ans%mod);
			return 0;
		}
	}
	if(p==0){
		printf("-1");
		return 0;
	}
	for(i=2;;i++){
		for(j=0;j<p;j++){
			if(s[d[j]]=='D'){
				ans+=(ymax+1-ymin)*(i*n%mod+d[j]+1)%mod;
				ans%=mod;
				xmax--;
			}
			if(s[d[j]]=='U'){
				ans+=(ymax+1-ymin)*(i*n%mod+d[j]+1)%mod;
				ans%=mod;
				xmin++;
			}
			if(s[d[j]]=='R'){
				ans+=(xmax+1-xmin)*(i*n%mod+d[j]+1)%mod;
				ans%=mod;
				ymax--;
			}
			if(s[d[j]]=='L'){
				ans+=(xmax+1-xmin)*(i*n%mod+d[j]+1)%mod;
				ans%=mod;
				ymin++;
			}
			if(xmax<xmin||ymax<ymin){
				printf("%I64d",ans%mod);
				return 0;
			}
		}
	}
	return 0;
}