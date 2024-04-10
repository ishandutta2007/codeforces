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
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
int value[1<<4][13][1<<4][13];
int mod=1e9+7;
struct matrix{
	int n;
	LL a[255][255];
	matrix(){
		memset(a,0,sizeof(a));
	}
	matrix operator* (const matrix &aa)const {
		matrix ret;
		ret.n=aa.n;
		for(int i = 0;i<n;i++){
			for(int j =0;j<n;j++){
				for(int k =0;k<n;k++){
					ret.a[i][j]+=a[i][k]*aa.a[k][j]%mod;
					ret.a[i][j]%=mod;
				}
			}
		}
		return ret;
	}
};
matrix f_pow(matrix a,int b){
	matrix res,temp=a;
	res.n=a.n;
	for(int i = 0;i<res.n;i++)
		res.a[i][i]=1;
	while(b){
		if(b&1)res=res*temp;
		temp=temp*temp;
		b>>=1;
	}
	return res;
}
int main(){
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	for(int i =0;i<(1<<m);i++){
		for(int j = 0;j<=k;j++){
			value[i][j][i>>1][j]=1;
			if(j!=k)
			value[i][j][(i>>1)+(1<<(m-1))][j+1]=__builtin_popcount(i)+1;
		}
	}
	matrix a;
	a.n=((1<<m)*(k+1));
	for(int i = 0;i<(1<<m);i++){
		for(int j  =0;j<=k;j++){
			for(int ii = 0;ii<(1<<m);ii++){
				for(int jj= 0;jj<=k;jj++){
					a.a[i*(k+1)+j][ii*(k+1)+jj]=value[i][j][ii][jj];
				//	printf("%d ",value[i][j][ii][jj]);
				}
			}
			//printf("\n");
		}
	}
//	printf("\n");
	a = f_pow(a,n);
	LL ans=0;
	for(int i = 0;i<(1<<m);i++){
		ans+=a.a[0][i*(k+1)+k];
	}
	printf("%lld\n",ans%mod);
}