#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int mod=1e9+7;
LL f[3][3]={
	{1,1,0},
	{1,1,1},
	{0,1,1}
};
struct matrix{
	LL a[3][3];
	matrix operator*(const matrix &b){
		matrix x;
		MEM(x.a);
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++)
				x.a[i][j]+=a[i][k]*b.a[k][j];
				x.a[i][j]%=mod;
			}
		return x;
	}
};
matrix f_pow(matrix a,LL b){
	matrix temp=a,res;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			res.a[i][j]=0;
			if(i==j)
			res.a[i][j]=1;
		}
	while(b){
		if(b&1)res=res*temp;
		temp=temp*temp;
		b>>=1;
	}
	return res;
}
int main(){
	LL n,m;
	scanf("%lld %lld",&n,&m);
	pll p[20005];
	for(int i=0;i<n;i++){
		int a;
		LL l,r;
		scanf("%d %lld %lld",&a,&l,&r);
		p[i*2]=mp(l,a);
		p[i*2+1]=mp(r+1,-a);
		if(a==2&&r==m){
			printf("0\n");
			return 0;
		}
	}
	sort(p,p+2*n);
	p[2*n]=mp(m+1,0);
	int now[3]={0,0,0};
	LL last=2;
	matrix res;
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			res.a[i][j]=0;
			if(i==j)
			res.a[i][j]=1;
		}
	for(int i=0;i<=2*n;i++){
		matrix a;
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				a.a[j][k]=f[j][k];
		for(int j=0;j<3;j++){
			if(now[j])
			for(int k=0;k<3;k++)
			a.a[k][j]=0;
		}
		if(p[i].x<last){
				break;
		}
		matrix temp=f_pow(a,p[i].x-last);
		res=res*temp;
		//printf("%d\n",p[i].x-last);
		if(p[i].y>0)
		now[p[i].y-1]++;
		else
		now[abs(p[i].y)-1]--;
		last=p[i].x;
	}
	printf("%lld\n",res.a[1][1]);
}
/*
BC
ACC
AABC
CC
ABC
AACC*/