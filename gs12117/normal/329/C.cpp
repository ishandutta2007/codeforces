#include<stdio.h>
int n,m;
int a[100100][2];
int b[100100][2];
int bn[100100];
int cl[100100];
int bns[10][2];
int ans[100100][2];
int chk[100100];
int left[100100];
int flag;
int f(int x,int y,int z){
	if(b[x][0]==y||b[x][1]==y)return 1;
	if(b[x][0]==z||b[x][1]==z)return 1;
	if(b[z][0]==y||b[z][1]==y)return 1;
	return 0;
}
void btrk(int ln,int lm,int loc,int p,int q){
	if(lm==loc){
		flag=1;
		return;
	}
	if(p==ln)return;
	if(p==q){
		btrk(ln,lm,loc,p+1,0);
		return;
	}
	if(b[cl[p]][0]!=cl[q]&&b[cl[p]][1]!=cl[q]&&left[cl[p]]<2&&left[cl[q]]<2){
		bns[loc][0]=cl[p];
		bns[loc][1]=cl[q];
		left[cl[p]]++;
		left[cl[q]]++;
		btrk(ln,lm,loc+1,p,q+1);
		left[cl[p]]--;
		left[cl[q]]--;
		if(flag==1)return;
	}
	btrk(ln,lm,loc,p,q+1);
}
int main(){
	int i,j,k,l,t;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		b[a[i][0]][bn[a[i][0]]]=a[i][1];
		bn[a[i][0]]++;
		b[a[i][1]][bn[a[i][1]]]=a[i][0];
		bn[a[i][1]]++;
	}
	for(i=0;i<n;i++){
		cl[i]=i+1;
	}
	if(n<=7){
		btrk(n,m,0,0,0);
		if(flag==0)printf("-1");
		else{
			for(i=0;i<m;i++){
				printf("%d %d\n",bns[i][0],bns[i][1]);
			}
		}
	}
	else{
		for(i=0;i<n-7;i+=3){
			for(j=0;j<7;j++){
				for(k=0;k<j;k++){
					for(l=0;l<k;l++){
						if(f(cl[n-i-1-j],cl[n-i-1-k],cl[n-i-1-l])==0)goto fin;
					}
				}
			}
fin:
			ans[i][0]=cl[n-i-1-j];
			ans[i][1]=cl[n-i-1-k];
			ans[i+1][0]=cl[n-i-1-j];
			ans[i+1][1]=cl[n-i-1-l];
			ans[i+2][0]=cl[n-i-1-k];
			ans[i+2][1]=cl[n-i-1-l];
			cl[n-i-1-j]=0;
			cl[n-i-1-k]=0;
			cl[n-i-1-l]=0;
			for(j=0;j<3;j++){
				if(cl[n-i-1-j]!=0){
					for(k=n-i-4;k>=0;k--){
						if(cl[k]==0){
							break;
						}
					}
					cl[k]=cl[n-i-1-j];
				}
			}
		}
		if(i>=m){
			for(i=0;i<m;i++){
				printf("%d %d\n",ans[i][0],ans[i][1]);
			}
		}
		else{
			for(j=0;j<i;j++){
				printf("%d %d\n",ans[j][0],ans[j][1]);
			}
			btrk(n-i,m-i,0,0,0);
			for(j=0;j<m-i;j++){
				printf("%d %d\n",bns[j][0],bns[j][1]);
			}
		}
	}
}