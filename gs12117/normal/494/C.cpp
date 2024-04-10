#include<stdio.h>
#include<algorithm>
int n,m;
int a[100100];
struct st{
	int px,py;
	double prob;
	bool operator<(const st&r)const{
		return px<r.px||(px==r.px&&py>r.py);
	}
}b[5010];
int mval[5010];
double prob[5010][5010];
double nprob[5010];
int udep[5010];
double ans;
int main(){
	int i,j,k,ii,jj,r;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d%d%lf",&b[i].px,&b[i].py,&b[i].prob);
		b[i].px--;
		b[i].py--;
	}
	b[m].px=0;
	b[m].py=n-1;
	b[m].prob=0;
	m++;
	std::sort(b,b+m);
	for(i=m-1;i>=0;i--){
		for(r=i+1;r<m&&b[i].py>=b[r].py;r++);
		k=b[i].px;
		for(j=i+1;j<r;j++){
			if(b[j].py>=k){
				while(k<b[j].px){
					if(mval[i]<a[k])mval[i]=a[k];
					k++;
				}
				if(mval[i]<mval[j])mval[i]=mval[j];
				k=b[j].py+1;
			}
		}
		while(k<=b[i].py){
			if(mval[i]<a[k])mval[i]=a[k];
			k++;
		}
		prob[i][0]=1;
		udep[i]=0;
		k=b[i].px-1;
		for(j=i+1;j<r;j++){
			if(b[j].px>k){
				for(ii=0;ii<=udep[i];ii++){
					for(jj=0;jj<=udep[j];jj++){
						if(ii>jj+mval[j]-mval[i]){
							nprob[ii]+=prob[i][ii]*prob[j][jj];
						}
						else{
							nprob[jj+mval[j]-mval[i]]+=prob[i][ii]*prob[j][jj];
						}
					}
				}
				if(udep[i]<udep[j]+mval[j]-mval[i])udep[i]=udep[j]+mval[j]-mval[i];
				for(ii=0;ii<=udep[i];ii++){
					prob[i][ii]=nprob[ii];
					nprob[ii]=0;
				}
				k=b[j].py;
			}
		}
		udep[i]++;
		for(j=0;j<udep[i];j++){
			nprob[j+1]+=b[i].prob*prob[i][j];
			nprob[j]+=(1-b[i].prob)*prob[i][j];
		}
		for(j=0;j<=udep[i];j++){
			prob[i][j]=nprob[j];
			nprob[j]=0;
		}
	}
	ans=mval[0];
	for(i=0;i<=udep[0];i++){
		ans+=prob[0][i]*i;
	}
	printf("%.20lf",ans);
}