#include<stdio.h>
#include<algorithm>
int n,m;
struct flight{
	int a,b,d;
	bool operator<(const flight&r)const{
		return d<r.d;
	}
};
flight fl[160];
int af;
int ttime;
int lvisit[160];
int ans;
int cycl[160];
int bfsq[160];
int qs,qe;
int bfschk[160];
int en[160];
int pchk[160];
int nvt[160];
int elist[160][160];
void fnext(){//calc state after one flight
	int i;
	for(i=1;i<=n;i++){
		pchk[i]=(lvisit[i]==ttime);
	}
	for(i=0;i<af;i++){
		if(pchk[fl[i].a]){
			lvisit[fl[i].b]=ttime+1;
		}
	}
	ttime++;
	if(ans==-1&&lvisit[n]!=-1)ans=ttime;
}
void cycclc(int x){//calculate cycl
	int i;
	for(i=1;i<=n;i++){
		bfschk[i]=-1;
	}
	qs=0;
	qe=1;
	bfsq[0]=x;
	bfschk[x]=0;
	while(qs<qe){
		for(i=0;i<en[bfsq[qs]];i++){
			if(elist[bfsq[qs]][i]==x){
				cycl[x]=bfschk[bfsq[qs]]+1;
				return;
			}
			if(bfschk[elist[bfsq[qs]][i]]==-1){
				bfschk[elist[bfsq[qs]][i]]=bfschk[bfsq[qs]]+1;
				bfsq[qe]=elist[bfsq[qs]][i];
				qe++;
			}
		}
		qs++;
	}
	cycl[x]=-1;
}
void addf(){//add one flight course
	elist[fl[af].a][en[fl[af].a]]=fl[af].b;
	en[fl[af].a]++;
	af++;
	int i;
	for(i=1;i<=n;i++){
		if(lvisit[i]!=ttime)lvisit[i]=-1;
		cycclc(i);
	}
}
void twarp(int x){
	int i;
	for(i=1;i<=n;i++){
		if(cycl[i]!=-1&&lvisit[i]!=-1){
			nvt[i]=lvisit[i]+(((x-500-lvisit[i])/cycl[i])*cycl[i]);
			while(x-500<nvt[i])nvt[i]-=cycl[i];
			while(x-500>=nvt[i])nvt[i]+=cycl[i];
		}
		else{
			nvt[i]=-1;
		}
	}
	ttime=x-500;
	while(ttime!=x){
		for(i=1;i<=n;i++){
			if(nvt[i]==ttime){
				lvisit[i]=ttime;
			}
		}
		fnext();
	}
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&fl[i].a,&fl[i].b,&fl[i].d);
	}
	std::sort(fl,fl+m);
	af=0;
	ttime=0;
	ans=-1;
	for(i=1;i<=n;i++){
		lvisit[i]=-1;
		cycl[i]=-1;
	}
	lvisit[1]=0;
	while(ans==-1){
		while(af!=m&&fl[af].d==ttime){
			addf();
		}
		if(af==m)break;
		if(fl[af].d-ttime>13000){
			for(i=0;i<6000;i++){
				fnext();
			}
			twarp(fl[af].d-6000);
		}
		while(fl[af].d!=ttime){
			fnext();
		}
	}
	if(ans==-1){
		for(i=0;i<6000;i++){
			fnext();
		}
	}
	if(ans==-1){
		printf("Impossible");
	}
	else{
		printf("%d",ans);
	}
	return 0;
}