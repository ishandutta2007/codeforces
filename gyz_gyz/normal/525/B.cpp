#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[200010];
int n,l,m,T[200010],i,b;
int main()
{
 scanf("%s",a+1);
 l=strlen(a+1);n=l/2;
 scanf("%d",&m);
 while (m--){
 scanf("%d",&b);T[b]++;
 }
 for (i=1;i<=n;i++){
 T[i]+=T[i-1];
 if (T[i]&1)swap(a[i],a[l-i+1]);
 }
 printf("%s",a+1);
 return 0;
}