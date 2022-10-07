#include<stdio.h>
#include<math.h>
int n;
int loc[110][2];
double hl[1001000][3];
int hn;
double ans;
bool trt(int i,int j,int k){
	int da,db,dc,l;
	da=(loc[i][0]-loc[j][0])*(loc[i][0]-loc[j][0])+(loc[i][1]-loc[j][1])*(loc[i][1]-loc[j][1]);
	db=(loc[k][0]-loc[j][0])*(loc[k][0]-loc[j][0])+(loc[k][1]-loc[j][1])*(loc[k][1]-loc[j][1]);
	dc=(loc[i][0]-loc[k][0])*(loc[i][0]-loc[k][0])+(loc[i][1]-loc[k][1])*(loc[i][1]-loc[k][1]);
	if(da>db+dc)return 0;
	if(db>da+dc)return 0;
	if(dc>db+da)return 0;
	if(da==db+dc){
		for(l=0;l<n;l++){
			if(loc[l][0]==loc[i][0]+loc[j][0]-loc[k][0]&&loc[l][1]==loc[i][1]+loc[j][1]-loc[k][1])break;
		}
		if(l==n)return 0;
	}
	if(db==da+dc){
		for(l=0;l<n;l++){
			if(loc[l][0]==loc[k][0]+loc[j][0]-loc[i][0]&&loc[l][1]==loc[k][1]+loc[j][1]-loc[i][1])break;
		}
		if(l==n)return 0;
	}
	if(dc==db+da){
		for(l=0;l<n;l++){
			if(loc[l][0]==loc[i][0]+loc[k][0]-loc[j][0]&&loc[l][1]==loc[i][1]+loc[k][1]-loc[j][1])break;
		}
		if(l==n)return 0;
	}
	return 1;
}
void calchl(int i,int j,int k){
	double a,b,c;
	a=loc[i][0]*loc[i][0]+loc[i][1]*loc[i][1];
	b=loc[j][0]*loc[j][0]+loc[j][1]*loc[j][1];
	c=loc[k][0]*loc[k][0]+loc[k][1]*loc[k][1];
	hl[hn][0]=(c-b)*loc[i][1]+(a-c)*loc[j][1]+(b-a)*loc[k][1];
	hl[hn][0]/=2*(loc[i][0]*loc[j][1]-loc[j][0]*loc[i][1]+loc[j][0]*loc[k][1]-loc[k][0]*loc[j][1]+loc[k][0]*loc[i][1]-loc[i][0]*loc[k][1]);
	hl[hn][1]=(c-b)*loc[i][0]+(a-c)*loc[j][0]+(b-a)*loc[k][0];
	hl[hn][1]/=2*(loc[i][1]*loc[j][0]-loc[j][1]*loc[i][0]+loc[j][1]*loc[k][0]-loc[k][1]*loc[j][0]+loc[k][1]*loc[i][0]-loc[i][1]*loc[k][0]);
	hl[hn][2]=sqrt((hl[hn][0]-loc[i][0])*(hl[hn][0]-loc[i][0])+(hl[hn][1]-loc[i][1])*(hl[hn][1]-loc[i][1]));
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&loc[i][0],&loc[i][1]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			for(k=0;k<j;k++){
				if(trt(i,j,k)){
					calchl(i,j,k);
					hn++;
				}
			}
		}
	}
	ans=-1;
	for(i=0;i<hn;i++){
		for(j=0;j<n;j++){
			if(hl[i][2]>sqrt((loc[j][0]-hl[i][0])*(loc[j][0]-hl[i][0])+(loc[j][1]-hl[i][1])*(loc[j][1]-hl[i][1]))*1.0000001){
				break;
			}
		}
		if(j==n&&hl[i][2]>ans)ans=hl[i][2];
	}
	if(ans<0.5)printf("-1");
	else printf("%.30lf",ans);
}