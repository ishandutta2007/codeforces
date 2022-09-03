#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
typedef complex<double> C;
LL mod=1e9+7;
struct matrix{
	LL a[105][105];
	int n;
	matrix(){
		memset(a,0,sizeof(a));
	}
};
matrix operator*(const matrix &a,const matrix &b){
	matrix res;
	res.n=a.n;
	int n=a.n;
	for(int i = 0;i<n;i++){
		for(int j =0;j<n;j++){
			for(int k=0;k<n;k++){
				res.a[i][j]+=a.a[i][k]*b.a[k][j];
				res.a[i][j]%=mod;
			}
		}
	}
	return res;
}
matrix f_pow(matrix a,LL b){
	matrix res,temp=a;
	res.n=a.n;
	for(int i =0;i<res.n;i++){
		res.a[i][i]=1;
	}
	while(b){
		if(b&1)res=res*temp;
		temp=temp*temp;
		b>>=1;
	}
	return res;
}
LL f_pow(LL a,LL b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int cnt=0;
	int a[105];
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		cnt+=a[i];
	}
	int one=cnt;
	int zero=n-cnt;
	cnt=0;
	for(int i = 0;i<zero;i++){
		cnt+=a[i];
	}
	matrix m;
	m.n=one+1;
	for(int i = 0;i<=one;i++){
		if(i>zero)
		break;
		m.a[i][i]=(LL)((zero*(zero-1))/2+one*(one-1)/2+i*(one-i)+(zero-i)*i)*f_pow(n*(n-1)/2,mod-2)%mod;
		if(i!=0)
		m.a[i][i-1]=(LL)(i*i)*f_pow(n*(n-1)/2,mod-2)%mod;
		if(i!=one)
		m.a[i][i+1]=(LL)((zero-i)*(one-i))*f_pow(n*(n-1)/2,mod-2)%mod;
	}
	/*for(int i = 0;i<=one;i++){
		for(int j = 0;j<=one;j++){
			printf("%d ",m.a[i][j]);
		}
		printf("\n");
	}*/
	matrix res=f_pow(m,k);
	printf("%lld\n",res.a[cnt][0]);
}