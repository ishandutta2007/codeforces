#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 1005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k;
unsigned long long C[N][N],ans;
int main()
{
	  scanf("%d",&n);
	  for (i=0;i<N;++i)
	  {
	  	  C[i][0]=1;
	  	  for (j=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1]);
	  }
	  for (i=5;i<=7;++i) ans+=C[n][i];
	  cout<<ans<<endl; 
}