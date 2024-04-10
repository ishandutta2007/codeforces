#include<stdio.h>
#include<algorithm>
int n,m;
int qry[200100][3];
int chk[200100];
struct peg{
	long long int val;
	int orig;
	bool operator<(const peg&r)const{
		return val<r.val;
	}
};
peg a[200100];
int qd[200100];
int bsrc(int x){
	int i,j;
	j=-1;
	for(i=20;i>=0;i--){
		j+=(1<<i);
		if(j>=n||a[j].val>=x)j-=(1<<i);
	}
	return j+1;
}
int main(){
	int i,j,pf;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%I64d",&a[i].val);
		a[i].orig=i+1;
	}
	std::sort(a,a+n);
	for(i=0;i<n;i++){
		qd[a[i].orig]=i;
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&qry[i][0],&qry[i][1]);
		int flag=1;
		pf=0;
		qry[i][0]=qd[qry[i][0]];
		qry[i][2]=0;
		while(1){
			if(qry[i][2]==0){
				j=bsrc(a[qry[i][0]].val+qry[i][1]+1)-1;
				if(j==qry[i][0]){
					pf=1;
					qry[i][2]^=1;
					continue;
				}
				else pf=0;
				if(chk[qry[i][0]]==i+1&&qry[i][1]/(a[j].val-a[qry[i][0]].val)>=2){
					qry[i][1]-=(qry[i][1]/(2*(a[j].val-a[qry[i][0]].val)))*2*(a[j].val-a[qry[i][0]].val);
					continue;
				}
				if(flag==0)chk[qry[i][0]]=i+1;
				qry[i][1]-=a[j].val-a[qry[i][0]].val;
				qry[i][2]^=1;
				qry[i][0]=j;
			}
			else{
				j=bsrc(a[qry[i][0]].val-qry[i][1]);
				if(j==qry[i][0]&&pf==1)break;
				if(j==qry[i][0]){
					qry[i][2]^=1;
					continue;
				}
				pf=0;
				qry[i][1]-=a[qry[i][0]].val-a[j].val;
				qry[i][2]^=1;
				qry[i][0]=j;
			}
			flag=0;
		}
		printf("%d\n",a[qry[i][0]].orig);
	}
}