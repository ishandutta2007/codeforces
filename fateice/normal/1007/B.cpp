#include<bits/stdc++.h>
#define L long long
using namespace std;
int t,a,b,c,x[100010],A[10],B[10],C[10];
L p,q,r;
inline int gcd(int n,int m)
{
    return m?gcd(m,n%m):n;
}
inline L js(int a,int b,int c)
{
    return (L)x[a]*x[b]*x[c];
}
inline void dfs(int i,int a,int b,int c,int k)
{
    if(i>6)
      {
       if(a)
         {
          //cout<<a<<" "<<b<<" "<<c<<" "<<k<<" ";
          L f,g,h;
          f=js(a,b,c);
          g=js(gcd(a,b),1,c)+js(gcd(a,c),1,b)+js(gcd(c,b),1,a);
          a=gcd(a,b);
          a=gcd(a,c);
          h=js(a,1,1);
          g-=3*h;
          f-=g+h;
          p+=f*k;
          q+=g*k;
          r+=h*k;
         }
       return;
      }
    dfs(i+1,a,b,c,k);
    dfs(i+1,gcd(a,A[i]),gcd(b,B[i]),gcd(c,C[i]),-k);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	for(i=1;i<=100000;i++)
	  for(j=i;j<=100000;j+=i)
	    x[j]++;
	scanf("%d",&t);
	while(t--)
	  {
       scanf("%d%d%d",&a,&b,&c);
       A[1]=a;
       B[1]=b;
       C[1]=c;
       A[2]=a;
       B[2]=c;
       C[2]=b;
       A[3]=b;
       B[3]=a;
       C[3]=c;
       A[4]=b;
       B[4]=c;
       C[4]=a;
       A[5]=c;
       B[5]=a;
       C[5]=b;
       A[6]=c;
       B[6]=b;
       C[6]=a;
       dfs(1,0,0,0,-1);
       //cout<<p<<" "<<q<<" "<<r<<"\n";
       printf("%lld\n",p/6+q/3+r);
       p=q=r=0;
      }
	return 0;
}