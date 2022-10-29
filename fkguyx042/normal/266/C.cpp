#include<cstdio>
#include<algorithm> 
#include<cstring>
using namespace std;
int b[3001][3],n,m,i,j,t,a[1001][2];
int main(){
   scanf("%d",&n);
   for(i=1;i<n;i++) scanf("%d %d",&a[i][0],&a[i][1]);
   for(i=1;i<n;i++)
   {if(a[i][0]!=i+1)
      { for(j=i+1;j<n;j++)if(a[j][0]==a[i][0])a[j][0]=i+1;
        else if(a[j][0]==i+1)a[j][0]=a[i][0];
        b[++t][0]=1,b[t][1]=a[i][0];b[t][2]=i+1,a[i][0]=i+1;
      }
        if(a[i][1]!=i&&a[i][1]>i)
        {   for(j=i+1;j<n;j++)if(a[j][1]==a[i][1])a[j][1]=i;
            else if(a[j][1]==i)a[j][1]=a[i][1];
            b[++t][0]=2,b[t][1]=a[i][1];b[t][2]=i,a[i][0]=i;}
	}
    printf("%d\n",t);
    for(i=1;i<=t;i++) printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
    return 0;
}