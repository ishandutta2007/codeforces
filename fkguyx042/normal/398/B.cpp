#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,X,Y;
double f[2055][2055];
int A[2055],B[2055];
int main()
{scanf("%d%d",&n,&m);
 for (i=1;i<=m;i++)
 {scanf("%d%d",&p,&k);
   if (!A[p]) {A[p]++; X++;}
   if (!B[k]) {B[k]++; Y++;}
}
 for (i=n;i>=X;i--)
   for (j=n;j>=Y;j--)
    if (i<n||j<n)
     f[i][j]=(n*n+(n-i)*j*f[i+1][j]+i*(n-j)*f[i][j+1]+(n-i)*(n-j)*f[i+1][j+1])/(n*n-i*j);
printf("%.10lf\n",f[X][Y]);
}