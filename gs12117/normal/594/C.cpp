#include<stdio.h>
#include<algorithm>
int n,m;
struct st{
	int loc;
	int val;
	bool operator<(const st&r)const{
		return val<r.val;
	}
};
st xs[100100];
st ys[100100];
long long int ans=2e18;
int chk[100100];
int a[100100][4];
int main(){
	int i,j,k,l,ii,chkn;
	long long int xt,yt;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		xs[i].loc=i;
		xs[i].val=a[i][0]+a[i][2];
		ys[i].loc=i;
		ys[i].val=a[i][1]+a[i][3];
	}
	std::sort(xs,xs+n);
	std::sort(ys,ys+n);
	for(i=0;i<=m;i++){
		for(j=0;j<=m;j++){
			for(k=0;k<=m;k++){
				for(l=0;l<=m;l++){
					chkn=0;
					for(ii=0;ii<i;ii++){
						if(chk[xs[ii].loc]==0)chkn++;
						chk[xs[ii].loc]=1;
					}
					for(ii=0;ii<j;ii++){
						if(chk[xs[n-1-ii].loc]==0)chkn++;
						chk[xs[n-1-ii].loc]=1;
					}
					for(ii=0;ii<k;ii++){
						if(chk[ys[ii].loc]==0)chkn++;
						chk[ys[ii].loc]=1;
					}
					for(ii=0;ii<l;ii++){
						if(chk[ys[n-1-ii].loc]==0)chkn++;
						chk[ys[n-1-ii].loc]=1;
					}
					if(chkn<=m){
						xt=xs[n-1-j].val-xs[i].val;
						yt=ys[n-1-l].val-ys[k].val;
						xt=(xt+1)/2;
						yt=(yt+1)/2;
						if(xt<1)xt=1;
						if(yt<1)yt=1;
						if(xt*yt<ans)ans=xt*yt;
					}
					for(ii=0;ii<i;ii++){
						chk[xs[ii].loc]=0;
					}
					for(ii=0;ii<j;ii++){
						chk[xs[n-1-ii].loc]=0;
					}
					for(ii=0;ii<k;ii++){
						chk[ys[ii].loc]=0;
					}
					for(ii=0;ii<l;ii++){
						chk[ys[n-1-ii].loc]=0;
					}
				}
			}
		}
	}
	printf("%I64d",ans);
}