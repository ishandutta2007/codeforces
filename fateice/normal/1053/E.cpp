#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,N,m,a[1000010],b[1000010],c[1000010],p,l[1000010],r[1000010],f[1000010];
inline void del(int i)
{
	//cout<<i<<" "<<l[i]<<" "<<r[i]<<"&&&\n";
	l[r[i]]=l[i];
	r[l[i]]=r[i];
}
inline void orz(int i,int j)
{
	int k;
	for(k=r[i];k!=j;)
	  if(k!=i && a[k] && !a[l[k]] && a[r[k]])
	    {
			//cerr<<k<<"!!!!\n";
		 a[l[k]]=a[r[k]];
		 del(k);
		 del(r[k]);
		 k=l[k];
		 if(k!=i)
		 k=l[k];
		}
	  else if(k!=i && a[k] && a[l[k]] && !a[r[k]])
	    {
			//cerr<<k<<"!!!!\n";
		 a[r[k]]=a[l[k]];
		 del(k);
		 del(r[k]);
		 k=l[k];
		 if(k!=i)
		 k=l[k];
		}
	  else
	    k=r[k];
	r[i]=r[j];
	l[r[j]]=i;
	//cout<<i<<" "<<j<<"----------\n";
}
int main()
{
	//freopen("E.in","r",stdin);
	//freopen("E.out","w",stdout);
	int i,j,k,u;
	scanf("%d",&n);
	N=2*n-1;
	for(i=1;i<=N;i++)
	  {
	   scanf("%d",&a[i]);
	   if(a[i] && !m)
	     m=i;
	  }
	if(!m)
	  {
	   printf("yes\n1 ");
	   for(i=2;i<=n;i++)
	     printf("%d 1 ",i);
	   printf("\n");
	   return 0;
	  }
	for(i=1;i<=N;i++)
	  b[i]=a[i];
	for(i=1,j=m;i<=N;i++,j=j%N+1)
	  a[i]=b[j];
	if(a[N]!=0 && a[N]!=a[1])
	  {
   	   printf("no\n");
	   return 0;
	  }
	a[N]=a[1];
	for(i=1;i<=N;i++)
	  l[i]=i-1,r[i]=i+1;
	for(i=1;i<=n;i++)
	  b[i]=0;
	for(i=1;i<=N;i++)
	  b[a[i]]=1;
	for(i=1;i<=n;i++)
	    {
	  if(!b[i])
		 c[++p]=i;
		 b[i]=0;
		}
	for(i=1;i<=N;i=r[i])
	{
		//cerr<<i<<"!!\n";
	  if(a[i])
	  if(!b[a[i]])
	    b[a[i]]=1;
	  else if(b[a[i]]==1)
	    {
		 for(j=l[i],k=1,u=1;a[j]!=a[i];j=l[j],u++)
		   if(a[j])
		     {
			  b[a[j]]=2;
			  k++;
			 }
		 //cout<<u<<" "<<k<<"!!\n";
		 u=u/2+1-k;
		 if(u<0)
	       {
			/*for(k=j;k!=i;k=r[k])
			  cout<<k<<" "<<a[k]<<"\n";
			for(k=1;k<=N;k++)
			  cout<<a[k]<<" ";
			for(k=1;k<=N;k++)
			  cout<<k<<" "<<l[k]<<" "<<r[k]<<"\n";*/
		    printf("no\n");
		    return 0;
	   	   }
	   	 for(k=j;k!=i;k=r[k])
	   	   if(!a[k] && u)
	   	     if(p)
	   	       a[k]=c[p--],u--;
	   	     else
	   	       {
				printf("no\n");
				return 0;
			   }
		 orz(j,i);
		}
	  else
	    {
		 printf("no\n");
		 return 0;
		}
	}
	for(i=1;i<=N;i++)
	  if(!a[i])
	    {
			//for(k=1;k<=N;k++)
			  //cout<<a[k]<<" ";
		 printf("no\n");
		 return 0;
		}
	f[a[1]]=-1;
	for(i=2,j=a[1];i<=N;i++)
	  {
	   if(a[i]==f[j])
	     j=f[j];
	   else if(!f[a[i]])
	     {
		  f[a[i]]=j;
		  j=a[i];
		 }
	   else
	     {
		  printf("no\n");
		  return 0;
	   	 }
	  }
	printf("yes\n");
	if(m!=1)
	  m=N-m+1;
	for(i=m;i<N;i++)
	  printf("%d ",a[i]);
	for(i=1;i<m;i++)
	  printf("%d ",a[i]);
	printf("%d\n",a[m]);
	return 0;
}