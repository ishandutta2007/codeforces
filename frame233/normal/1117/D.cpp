#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
const int mod=1000000007;
int m;
inline void add(int &a,const int &b){(a+=b)>=mod&&(a-=mod);}
struct matrix{
    int a[101][101];
    matrix operator * (const matrix &b)const
    {
        matrix c;
        memset(c.a,0,sizeof(c.a));
        for(register int i=0;i<m;++i)
        {
            for(register int k=0;k<m;++k)
            {
            	for(register int j=0;j<m;++j)
   	        	{
       	     	    add(c.a[i][j],1LL*a[i][k]*b.a[k][j]%mod);
				}
            }
        }
        return c;
    }
}f,now,res;
matrix mul(const matrix &a,const matrix &b)
{
    matrix c;
    memset(c.a,0,sizeof(c.a));
    for(register int i=0;i<m;++i)
    {
        for(register int k=0;k<m;++k)
        {
            add(c.a[i][1],1LL*a.a[i][k]*b.a[k][1]%mod);
        }
	}
    return c;
}
int main()
{
	ll n;
	scanf("%lld %d",&n,&m);
	for(register int i=0;i<m;++i)
	{
		f.a[i][1]=1;
		res.a[i][i]=1;
	}
	for(register int i=1;i<m;++i)
	{
		now.a[i][i-1]=1;
	}
	now.a[0][0]=now.a[0][m-1]=1;
	n-=m-2;
	while(n>0)
	{
		if(n&1) f=mul(now,f);
		now=now*now,n>>=1;
	}
	printf("%d\n",f.a[1][1]%mod);
	return 0;
}