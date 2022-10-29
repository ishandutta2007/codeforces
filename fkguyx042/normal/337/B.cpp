#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,x,y,Gcd;
int a,b,c,d;
int gcd(int a,int b)
{ if (!b) return a; return gcd(b,a%b); }
int main()
{ scanf("%d%d%d%d",&a,&b,&c,&d);
 if (a*d==b*c) { printf("0/1\n"); }
 else {  if (a*d>b*c) {  x=d*a-b*c; y=a*d;Gcd=gcd(x,y);
   printf("%d/%d\n",x/Gcd,y/Gcd);
} else {  x=b*c-a*d; y=b*c; Gcd=gcd(x,y); printf("%d/%d\n",x/Gcd,y/Gcd); }
}
}