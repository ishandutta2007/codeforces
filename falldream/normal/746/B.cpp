#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
   int x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
int n;
char s[2005];
char s2[2005];
int main()
{
    n=read();
    scanf("%s",s+1);
    for(int i=1,j=(n+1)/2,k=n/2+1;i<=n;)
    {
	if(j!=k)
	s2[j--]=s[i++];
	else j--;
	s2[k++]=s[i++];
    } 
    for(int i=1;i<=n;i++) cout<<s2[i];
    return 0;
}