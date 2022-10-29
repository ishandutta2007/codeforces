#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,A,b,c,d;
char C[101];
int a[101][2];
int main()
 {scanf("%d %d",&A,&b);
   scanf("%s",&C);
   n=strlen(C);
   for (i=1;i<=strlen(C);i++)
    if (C[i-1]=='R') a[i][0]=a[i-1][0]+1,a[i][1]=a[i-1][1];
 else if (C[i-1]=='L') a[i][0]=a[i-1][0]-1,a[i][1]=a[i-1][1];
 else if (C[i-1]=='U') a[i][1]=a[i-1][1]+1,a[i][0]=a[i-1][0];
 else if (C[i-1]=='D') a[i][1]=a[i-1][1]-1,a[i][0]=a[i-1][0]; 
  if (A==0&&b==0) { printf("Yes\n"); return 0;}
       for (i=0;i<=n;i++)
   { c=A-a[i][0];
     d=b-a[i][1];
     if (c==0&&d==0) {printf("Yes\n"); return 0;}
     if (c>=0&&a[n][0]<0) continue;
     if (d>=0&&a[n][1]<0) continue;
     if (c<=0&&a[n][0]>0) continue;
     if (d<=0&&a[n][1]>0) continue;
     if (c==0&&a[n][0]!=0) continue;
     if (d==0&&a[n][1]!=0) continue;
     if (c!=0&&a[n][0]==0) continue;
     if (d!=0&&a[n][1]==0) continue;
     c=abs(c);
     d=abs(d);
       if (a[n][0]!=0)
     if (c%abs(a[n][0])!=0) continue;
     if (a[n][1]!=0)
      if (d%abs(a[n][1])!=0) continue;
      if (a[n][0]!=0&&a[n][1]!=0) 
        if (c/abs(a[n][0])!=d/abs(a[n][1])) continue;
      printf("Yes\n");
      return 0;
      }
   printf("No\n");
   return 0;
}