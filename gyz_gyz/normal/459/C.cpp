#include <stdio.h>
#include <string.h>
using namespace std;
int a[2001][2001];
int n,k,d,s;
int main(){
    scanf("%d%d%d",&n,&k,&d);s=0;
    if ((k==1)&&(n>1)) {puts("-1");return 0;}
    for (int p=n;p>1;p=(p-1)/k+1) s++;
    if (s>d) {puts("-1");return 0;}
    for (int i=1;i<=d;i++) a[1][i]=1;
    for (int i=2;i<=n;i++){
        for (int j=1;j<=d;j++) a[i][j]=a[i-1][j];
        for (s=d;a[i][s]==k;s--);
        a[i][s]++;s++;
        for (;s<=d;s++) a[i][s]=1;
    }
    for (int j=1;j<=d;j++){
        for (int i=1;i<=n;i++) printf("%d ",a[i][j]);
        puts("");
   }
   return 0;
}