#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=1E6+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(!(c&16));
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
char a[N],b[N];int l[26],r[26];
int main()
{
	for(int x=read();x--;)
	{	
		int n=read(),k=read(),s1=0,s2=0;
		scanf("%s%s",a,b),memset(l,0,sizeof l),memset(r,0,sizeof r);
		for(int i=n;i--;)++l[a[i]-97],++r[b[i]-97];
		for(int i=26,t;i--;)t=min(l[i],r[i]),l[i]-=t,r[i]-=t;
		int i=0;
		for(;i<26;++i)
		{
			if(l[i]%k||r[i]%k)break;
			s1+=l[i],s2+=r[i];
			if(s1<s2)break;
		}
		puts(i==26?"Yes":"No");
	}
	return 0;
}