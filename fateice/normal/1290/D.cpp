#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,t,x[2000],p,q;
bool y[2000];
char s[10];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,u,v;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	  {
       printf("? %d\n",i);
       fflush(stdout);
       scanf("%s",&s);
       if(s[0]=='N')
         x[++p]=i;
      }
    m++;
    t=(m-m/2)*2;
	for(i=m;i<=n;i+=m/2)
	  {
       for(u=1;u<=p;u+=t)
       {
       printf("R\n");
       fflush(stdout);
       for(j=1;j<=m-m/2 && u+j-1<=p;j++)
       {
       printf("? %d\n",x[u+j-1]);
       fflush(stdout);
       scanf("%s",&s);
       }
       for(k=0;k<m/2;k++)
       if(!y[i+k])
       {
       printf("? %d\n",i+k);
       fflush(stdout);
       scanf("%s",&s);
       if(s[0]=='Y')
         y[i+k]=1;
       }
       for(;j<=t && u+j-1<=p;j++)
       {
       printf("? %d\n",x[u+j-1]);
       fflush(stdout);
       scanf("%s",&s);
       if(s[0]=='Y')
         x[u+j-1]=0;
       }
       }
       for(j=1;j<=p;j++)
         if(x[j]==0)
           {
            swap(x[j],x[p]);
            j--;
            p--;
           }
       for(k=0;k<m/2;k++)
         if(!y[i+k])
           x[++p]=i+k;
      }
    printf("! %d\n",p);
    fflush(stdout);
	return 0;
}