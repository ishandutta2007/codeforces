#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int read()
{
   int x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
int n,k,a,b;
int main()
{
    n=read();k=read();a=read();b=read(); bool yes=false;
    if((b+k-1)/k-1>a||(a+k-1)/k-1>b){ printf("NO");return 0;}
    while(a!=b)
    {
	if(a>b) {int x=min(a,k);for(int j=1;j<=x;j++)printf("G");a-=x;
		    if(a>b) b-=1,printf("B");
 		    else if(a==b) {yes=true;break;}
		    else {for(int j=b;j>a;j--) printf("B");b=a;}
		}
         else   {int x=min(b,k);b-=x;
                    for(int j=1;j<=x;j++) printf("B");
             if(b>a) a-=1,printf("G");
		    else if(a==b) {yes=false;break;}
		    else {for(int j=a;j>b;j--) printf("G");a=b;}
         }
    }
    while(a>0)
    {
	if(yes==true) printf("BG");
	else printf("GB");
	a--;
    }
    return 0;
}