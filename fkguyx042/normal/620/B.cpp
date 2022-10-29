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

#define N 1000005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,f[N],a,b;
int main()
{
	 f[0]=6; f[1]=2; f[2]=f[3]=f[5]=5; f[4]=4;f[6]=6; f[7]=3;f[9]=6; f[8]=7;
	 for(i=10;i<N;++i) f[i]=f[i/10]+f[i%10]; 
	 scanf("%d%d",&a,&b);
     int ans=0;
     for (i=a;i<=b;++i) ans+=f[i];
     printf("%d\n",ans);
}