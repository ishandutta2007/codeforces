#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 105
const ll mod=1000000007;
ll n;
int m;
struct matrix{
	ll g[N][N];
	matrix(){memset(g,0,sizeof(g));}
	matrix operator *(matrix &a){
		matrix b;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=m;k++){
					b.g[i][j]+=g[i][k]*a.g[k][j];
					b.g[i][j]%=mod;
				}
			}
		}
		return b;
	}
}s,e,f;
matrix mpow(matrix a,ll b){
	matrix ans=e;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<m;i++){
		s.g[i][i+1]=1;
	}
	s.g[m][1]=s.g[m][m]=1;
	for(int i=1;i<=m;i++){
		e.g[i][i]=1;
		f.g[i][1]=1;
	}
	matrix ans=mpow(s,n);
	ans=ans*f;
	cout<<ans.g[1][1]<<endl;
	return 0;
}