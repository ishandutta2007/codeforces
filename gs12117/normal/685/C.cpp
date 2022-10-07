#include<stdio.h>
int tc;
int n;
long long int a[100100][3];
long long int res[3];
int ff(long long int pa,long long int pb,long long int pc,long long int pd,long long int qa,long long int qb,long long int qc,long long int qd,int z){
	if(pa>qa)return 0;
	if(pb>qb)return 0;
	if(pc>qc)return 0;
	if(pd>qd)return 0;
	long long int ra,rb,rc;
	ra=pa;
	rb=pb;
	rc=pc;
	if(ra+rb+rc-z<pd){
		ra+=pd-(ra+rb+rc-z);
		if(ra>qa)ra=qa;
	}
	if(ra+rb+rc-z<pd){
		rb+=pd-(ra+rb+rc-z);
		if(rb>qb)rb=qb;
	}
	if(ra+rb+rc-z<pd){
		rc+=pd-(ra+rb+rc-z);
		if(rc>qc)rc=qc;
	}
	if(ra+rb+rc-z<pd){
		return 0;
	}
	if(ra+rb+rc-z>qd){
		return 0;
	}
	res[0]=rb+rc-z;
	res[1]=ra+rc-z;
	res[2]=ra+rb-z;
	return 1;
}
int f(long long int x){
	int i;
	long long int pa,pb,pc,pd,qa,qb,qc,qd;
	long long int tpa,tpb,tpc,tpd,tqa,tqb,tqc,tqd;
	if(x>3.01e18)return 1;
	pa=-a[0][0]+a[0][1]+a[0][2]+x;
	pb=a[0][0]-a[0][1]+a[0][2]+x;
	pc=a[0][0]+a[0][1]-a[0][2]+x;
	pd=a[0][0]+a[0][1]+a[0][2]+x;
	qa=-a[0][0]+a[0][1]+a[0][2]-x;
	qb=a[0][0]-a[0][1]+a[0][2]-x;
	qc=a[0][0]+a[0][1]-a[0][2]-x;
	qd=a[0][0]+a[0][1]+a[0][2]-x;
	for(i=1;i<n;i++){
		tpa=-a[i][0]+a[i][1]+a[i][2]+x;
		tpb=a[i][0]-a[i][1]+a[i][2]+x;
		tpc=a[i][0]+a[i][1]-a[i][2]+x;
		tpd=a[i][0]+a[i][1]+a[i][2]+x;
		tqa=-a[i][0]+a[i][1]+a[i][2]-x;
		tqb=a[i][0]-a[i][1]+a[i][2]-x;
		tqc=a[i][0]+a[i][1]-a[i][2]-x;
		tqd=a[i][0]+a[i][1]+a[i][2]-x;
		if(tpa<pa)pa=tpa;
		if(tpb<pb)pb=tpb;
		if(tpc<pc)pc=tpc;
		if(tpd<pd)pd=tpd;
		if(tqa>qa)qa=tqa;
		if(tqb>qb)qb=tqb;
		if(tqc>qc)qc=tqc;
		if(tqd>qd)qd=tqd;
	}
	if(ff((qa+1)>>1,(qb+1)>>1,(qc+1)>>1,(qd+1)>>1,pa>>1,pb>>1,pc>>1,pd>>1,0))return 1;
	if(ff((qa+2)>>1,(qb+2)>>1,(qc+2)>>1,(qd+2)>>1,(pa+1)>>1,(pb+1)>>1,(pc+1)>>1,(pd+1)>>1,1))return 1;
	return 0;
}
int main(){
	int i;
	long long int ans;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%I64d%I64d%I64d",&a[i][0],&a[i][1],&a[i][2]);
		}
		ans=-1;
		for(i=61;i>=0;i--){
			ans+=1LL<<i;
			if(f(ans))ans-=1LL<<i;
		}
		ans++;
		f(ans);
		printf("%I64d %I64d %I64d\n",res[0],res[1],res[2]);
	}
}