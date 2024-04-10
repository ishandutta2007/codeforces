#include<stdio.h>
#include<algorithm>
int n,l;
char ans[2001000];
struct node{
	long long int t,x,y;
	long long int cyc;
	long long int pha;
	bool operator<(const node&r)const{
		return pha<r.pha;
	}
};
node p[200100];
long long int minp,maxp,minm,maxm;
long long int vx,vy;
long long int mabs(long long int x){
	if(x>0)return x;
	return -x;
}
int main(){
	int i,j;
	long long int ax,ay,bx,by,cycd,phad;
	scanf("%d%d",&n,&l);
	for(i=1;i<=n;i++){
		scanf("%I64d%I64d%I64d",&p[i].t,&p[i].x,&p[i].y);
		p[i].cyc=p[i].t/l;
		p[i].pha=p[i].t%l;
		if((p[i].x+p[i].y+p[i].t)%2==1){
			printf("NO");
			return 0;
		}
	}
	p[0].t=0;
	p[0].x=0;
	p[0].y=0;
	p[0].cyc=0;
	p[0].pha=0;
	for(i=0;i<n-1;i++){
		if(p[i+1].t-p[i].t<mabs(p[i].x-p[i+1].x)+mabs(p[i].y-p[i+1].y)){
			printf("NO");
			return 0;
		}
	}
	p[n+1].t=0;
	p[n+1].x=0;
	p[n+1].y=0;
	p[n+1].cyc=-1;
	p[n+1].pha=l;
	n+=2;
	std::sort(p,p+n);
	minp=-l;
	minm=-l;
	maxp=l;
	maxm=l;
	for(i=0;i<n-1;i++){
		phad=p[i+1].pha-p[i].pha;
		if(p[i].cyc>p[i+1].cyc){
			cycd=p[i].cyc-p[i+1].cyc;
			ax=p[i+1].x-p[i].x;
			ay=p[i+1].y-p[i].y;
		}
		else if(p[i].cyc<p[i+1].cyc){
			cycd=p[i+1].cyc-p[i].cyc;
			ax=p[i].x-p[i+1].x;
			ay=p[i].y-p[i+1].y;
		}
		else continue;
		while(minp<=maxp&&cycd*maxp>phad-ax-ay){
			maxp--;
		}
		while(minp<=maxp&&cycd*minp<-phad-ax-ay){
			minp++;
		}
		while(minm<=maxm&&cycd*maxm>phad-ax+ay){
			maxm--;
		}
		while(minm<=maxm&&cycd*minm<-phad-ax+ay){
			minm++;
		}
	}
	if(((minp+2*l)%2)!=l%2)minp++;
	if(((minm+2*l)%2)!=l%2)minm++;
	if(minp>maxp||minm>maxm){
		printf("NO");
		return 0;
	}
	vx=(minp+minm+2*l)/2-l;
	vy=(minp-minm+2*l)/2-l;
	for(i=0;i<n;i++){
		p[i].x-=vx*p[i].cyc;
		p[i].y-=vy*p[i].cyc;
	}
	j=0;
	for(i=0;i<n-1;i++){
		while(p[i].x<p[i+1].x){
			p[i].x++;
			ans[j]='R';
			j++;
		}
		while(p[i].x>p[i+1].x){
			p[i].x--;
			ans[j]='L';
			j++;
		}
		while(p[i].y<p[i+1].y){
			p[i].y++;
			ans[j]='U';
			j++;
		}
		while(p[i].y>p[i+1].y){
			p[i].y--;
			ans[j]='D';
			j++;
		}
		while(j<p[i+1].pha){
			ans[j]='R';
			j++;
			ans[j]='L';
			j++;
		}
	}
	printf("%s",ans);
}