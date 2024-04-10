#include<stdio.h>
int n,m;
int y[310][310];
double ans[310];
int chl[310];
double clp[310];
int nchl[310];
double nclp[310];
int nchln;
int chln;
int main(){
	int i,j,k,l,crossed;
	double crxa,cry;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<=m;j++){
			scanf("%d",&y[i][j]);
		}
	}
	for(i=0;i<m;i++){
		ans[0]+=((double)y[0][i]+y[0][i+1])/2;
		for(j=0;j<n+3;j++){
			chl[i]=0;
			clp[i]=0;
		}
		chl[0]=0;
		clp[0]=0;
		clp[1]=1;
		chln=1;
		for(j=1;j<n;j++){
			crossed=0;
			if(y[chl[0]][i]<y[j][i]){
				crossed=1;
				nchl[0]=j;
				nclp[0]=0;
				nchln=0;
			}
			for(k=0;k<chln;k++){
				if(crossed==1){
					ans[j]+=(clp[k+1]-clp[k])*(clp[k+1]*(y[j][i+1]-y[j][i])+y[j][i]-clp[k+1]*(y[chl[k]][i+1]-y[chl[k]][i])-y[chl[k]][i])/2;
					ans[j]+=(clp[k+1]-clp[k])*(clp[k]*(y[j][i+1]-y[j][i])+y[j][i]-clp[k]*(y[chl[k]][i+1]-y[chl[k]][i])-y[chl[k]][i])/2;
					if(y[chl[k]][i+1]-y[chl[k]][i]>y[j][i+1]-y[j][i]){
						crxa=((double)y[j][i]-y[chl[k]][i])/((double)y[chl[k]][i+1]-y[chl[k]][i]-y[j][i+1]+y[j][i]);
						if(clp[k+1]>crxa){
							ans[j]-=(clp[k+1]-clp[k])*(clp[k+1]*(y[j][i+1]-y[j][i])+y[j][i]-clp[k+1]*(y[chl[k]][i+1]-y[chl[k]][i])-y[chl[k]][i])/2;
							ans[j]-=(clp[k+1]-clp[k])*(clp[k]*(y[j][i+1]-y[j][i])+y[j][i]-clp[k]*(y[chl[k]][i+1]-y[chl[k]][i])-y[chl[k]][i])/2;
							ans[j]+=(crxa-clp[k])*(clp[k]*(y[j][i+1]-y[j][i])+y[j][i]-clp[k]*(y[chl[k]][i+1]-y[chl[k]][i])-y[chl[k]][i])/2;
							break;
						}
					}
				}
				else{
					nchl[k]=chl[k];
					nclp[k]=clp[k];
					if(crossed==0&&y[chl[k]][i+1]-y[chl[k]][i]>=y[j][i+1]-y[j][i])break;
					crxa=((double)y[j][i]-y[chl[k]][i])/((double)y[chl[k]][i+1]-y[chl[k]][i]-y[j][i+1]+y[j][i]);
					if(crossed==0&&clp[k+1]>crxa){
						crossed=1;
						nchl[k+1]=j;
						nclp[k+1]=crxa;
						nchln=k+1;
						ans[j]+=(clp[k+1]-crxa)*(clp[k+1]*(y[j][i+1]-y[j][i])+y[j][i]-clp[k+1]*(y[chl[k]][i+1]-y[chl[k]][i])-y[chl[k]][i])/2;
					}
				}
			}
			if(crossed==1){
				for(l=chln+1;l>nchln;l--){
					chl[l]=chl[l-1];
					clp[l]=clp[l-1];
				}
				chl[nchln]=nchl[nchln];
				clp[nchln]=nclp[nchln];
				if(k!=chln){
					clp[nchln+1]=crxa;
					for(l=nchln+1;l<chln-k+nchln+1;l++){
						chl[l]=chl[l+k-nchln];
						clp[l+1]=clp[l+k-nchln+1];
					}
				}
				else{
					clp[nchln+1]=1;
				}
				chln=chln-k+nchln+1;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%.10lf\n",ans[i]);
	}
}