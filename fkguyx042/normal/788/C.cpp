#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 10005
#define M 5000
#define L 1000
#define seed 23333

using namespace std;
const int inf=(int)1e9;
int i,j,m,n,p,k,f[N],x,A[N],Q[N+10];
bool check(int x)
{
		if (x<0||x>=N||f[x]<inf) return 0;
		return 1;
}
int main()
{
		scanf("%d%d",&n,&k);
		for (i=1;i<=k;++i) scanf("%d",&x),A[x]=1;
		memset(f,60,sizeof(f));
		for (i=0;i<=L;++i) 
				if (A[i]) f[i+M-n]=1,Q[++Q[0]]=i+M-n;
		for (int l=1;l<=Q[0];++l)
		{
				int p=Q[l];
				for (i=0;i<=L;++i)
					if (A[i]&&check(p+i-n))
						f[p+i-n]=f[p]+1,Q[++Q[0]]=p+i-n;
		}
		if (f[M]>inf) puts("-1");
		else printf("%d\n",f[M]); 
}