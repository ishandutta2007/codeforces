#include<stdio.h>
#include<algorithm>
int n,q;
long long int aa[30100];
long long int bb[30100];
long long int *a=aa+10;
long long int *b=bb+10;
int aord[30100];
int apord[30100];
int bord[30100];
int qry[100100][2];
struct st{
	int x,y;
	bool operator<(const st&r)const{
		return x<r.x;
	}
};
st p[30100];
long long int v[30100][6];
long long int dp[30100][6];
const long long int minf=-999999999999999999LL;
struct itnod{
	int live;
	long long int c[6][6];
	itnod operator+(const itnod&r)const{
		if(r.live==0)return *this;
		if(live==0)return r;
		itnod s;
		int i,j,k;
		s.live=1;
		for(i=0;i<6;i++){
			for(j=0;j<6;j++){
				s.c[i][j]=minf;
				for(k=0;k<6;k++){
					if(s.c[i][j]<r.c[i][k]+c[k][j]){
						s.c[i][j]=r.c[i][k]+c[k][j];
					}
				}
			}
		}
		return s;
	}
};
itnod it[1<<16];
void ks(int x){
	int d=x+(1<<15);
	it[d].live=1;
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			it[d].c[i][j]=minf;
		}
	}
	if(x+2!=bord[aord[x]]){
		it[d].c[2][0]=v[x][4];
		it[d].c[4][1]=v[x][4];
		it[d].c[5][2]=v[x][4];
	}
	if(x+1!=bord[aord[x]]){
		it[d].c[1][0]=v[x][3];
		it[d].c[3][1]=v[x][3];
	}
	if(x!=bord[aord[x]]){
		it[d].c[0][0]=v[x][2];
		it[d].c[3][2]=v[x][2];
	}
	if(x-1!=bord[aord[x]]){
		it[d].c[0][1]=v[x][1];
		it[d].c[1][2]=v[x][1];
	}
	if(x-2!=bord[aord[x]]){
		it[d].c[0][3]=v[x][0];
		it[d].c[1][4]=v[x][0];
		it[d].c[3][5]=v[x][0];
	}
}
void prop(int x){
	x+=1<<15;
	x/=2;
	while(x!=0){
		it[x]=it[x*2]+it[x*2+1];
		x/=2;
	}
}
int main(){
	int i,j,t;
	long long int tmp;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		scanf("%I64d",&a[i]);
		p[i].x=a[i];
		p[i].y=i;
	}
	std::sort(p,p+n);
	for(i=0;i<n;i++){
		aord[i]=p[i].y;
		apord[p[i].y]=i;
	}
	for(i=0;i<n;i++){
		scanf("%I64d",&b[i]);
		p[i].x=b[i];
		p[i].y=i;
	}
	std::sort(p,p+n);
	for(i=0;i<n;i++){
		bord[p[i].y]=i;
	}
	std::sort(a,a+n);
	std::sort(b,b+n);
	for(i=0;i<n;i++){
		for(j=0;j<5;j++){
			v[i][j]=a[i]*b[i-2+j];
		}
	}
	for(i=0;i<n;i++){
		ks(i);
	}
	for(i=(1<<15)-1;i>0;i--){
		it[i]=it[i*2]+it[i*2+1];
	}
	for(i=0;i<q;i++){
		scanf("%d%d",&qry[i][0],&qry[i][1]);
		qry[i][0]--;
		qry[i][1]--;
		t=bord[qry[i][0]];
		bord[qry[i][0]]=bord[qry[i][1]];
		bord[qry[i][1]]=t;
		ks(apord[qry[i][0]]);
		prop(apord[qry[i][0]]);
		ks(apord[qry[i][1]]);
		prop(apord[qry[i][1]]);
/*		for(j=t;j>=0;j--){
			dp[j][0]=minf;
			dp[j][1]=minf;
			dp[j][2]=minf;
			dp[j][3]=minf;
			dp[j][4]=minf;
			dp[j][5]=minf;
			if(j+2!=bord[aord[j]]){
				tmp=c[j][4];
				dp[j][0]=dp[j+1][2]+tmp;
				dp[j][1]=dp[j+1][4]+tmp;
				dp[j][2]=dp[j+1][5]+tmp;
			}
			if(j+1!=bord[aord[j]]){
				tmp=c[j][3];
				if(dp[j][0]<dp[j+1][1]+tmp){
					dp[j][0]=dp[j+1][1]+tmp;
				}
				if(dp[j][1]<dp[j+1][3]+tmp){
					dp[j][1]=dp[j+1][3]+tmp;
				}
			}
			if(j!=bord[aord[j]]){
				tmp=c[j][2];
				if(dp[j][0]<dp[j+1][0]+tmp){
					dp[j][0]=dp[j+1][0]+tmp;
				}
				if(dp[j][2]<dp[j+1][3]+tmp){
					dp[j][2]=dp[j+1][3]+tmp;
				}
			}
			if(j-1!=bord[aord[j]]){
				tmp=c[j][1];
				if(dp[j][1]<dp[j+1][0]+tmp){
					dp[j][1]=dp[j+1][0]+tmp;
				}
				if(dp[j][2]<dp[j+1][1]+tmp){
					dp[j][2]=dp[j+1][1]+tmp;
				}
			}
			if(j-2!=bord[aord[j]]){
				tmp=c[j][0];
				dp[j][3]=dp[j+1][0]+tmp;
				dp[j][4]=dp[j+1][1]+tmp;
				dp[j][5]=dp[j+1][3]+tmp;
			}
		}*/
		printf("%I64d\n",it[1].c[0][0]);
	}
}