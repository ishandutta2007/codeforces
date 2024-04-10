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

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,A[N];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
	    scanf("%d",&k);
		if (k) A[++A[0]]=p,p=0;
        else p++;		 
    }
    A[++A[0]]=p;
    if (A[0]==1) printf("0\n");
    else 
    {
    	 unsigned long long sum=1;
    	 for (i=2;i<A[0];++i) sum*=(A[i]+1);
    	 cout<<sum<<endl;
    }
}