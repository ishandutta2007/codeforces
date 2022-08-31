#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,p,a[200010],b[200010],l[200010],r[200010],y[200010];
bool u[200010];
L x[200010],w[200010];
char s[200010];
L q;
inline int ran()
{
    int i,k=(rand()<<14)+rand()+5e8;
    for(;;k++)
      {
       for(i=2;i*i<=k;i++)
         if(k%i==0)
           break;
       if(i*i>k)
         return k;
      }
}
inline void init()
{
    q=ran();
    q*=ran();
}
inline L mult(L x,L y)
{
    return (x*y-(L)((long double)x/q*y)*q+q)%q;     
}
inline L get_(int l,int r,int a,int b)
{
    int k=y[r]-y[l]+1;
    L p=(x[r]-mult(x[::l[l]],w[k]))%q;
    if(a)
      p=(p+2*w[k])%q;
    if(b)
      p=(p*3+2)%q;
    if(p<0)
      p+=q;
    return p;
}
inline L get(int i,int j)
{
    int ii=(u[i]?i:r[i]),jj=(u[j]?j:l[j]),k=0,kk=0;
    if(ii>jj)
      return (j-i+1&1)*2;
    if(ii-i&1)
      if(b[ii]==1)
        ii=r[ii];
      else
        k=1;
    if(ii>jj)
      return (j-jj&1)*2;
    if(j-jj&1)
      if(b[jj]==1)
        jj=l[jj];
      else
        kk=1;
    if(ii>jj)
      return 0;
    return get_(ii,jj,k,kk);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%s",&n,&s);
	for(i=1;i<=n;i++)
	  if(s[i-1]=='1' && p && b[a[p]])
	    p--;
	  else
	    {
	     a[++p]=i;
	     b[i]=s[i-1]-'0';
        }
	srand(time(0));
	init();
	for(i=1,j=1,k=0;i<=n;i++)
	  {
       l[i]=k;
	   if(j<=p && a[j]==i)
	     {
          k=i;
          j++;
          u[i]=1;
         }
      }
	for(i=n,j=p,k=n+1;i>0;i--)
	  {
       r[i]=k;
	   if(a[j]==i)
	     {
          k=i;
          j--;
         }
      }
    for(i=1;i<=p;i++)
      x[a[i]]=(x[a[i-1]]*3+b[a[i]]+1)%q,y[a[i]]=y[a[i-1]]+1;
    w[0]=1;
    for(i=1;i<=n;i++)
      w[i]=w[i-1]*3%q;
    scanf("%d",&m);
    while(m--)
      {
       scanf("%d%d%d",&i,&j,&k);
       if(get(i,i+k-1)==get(j,j+k-1))
         printf("Yes\n");
       else
         printf("No\n");
      }
	return 0;
}