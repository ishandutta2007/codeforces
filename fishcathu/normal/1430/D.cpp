#include<cstdio>
#include<cstring>
const int N=2E5;
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
int a[N];
int main()
{
    for(int x=read();x--;memset(a,0,sizeof a))
	{
		int n=read(),s=0,ans=0;
		char c;
		while(!(c=getchar())&16);
		a[0]=1;
		for(int i=n;--i;)
		{
			char t=getchar();
			t==c?++a[s]:a[++s]=1,c=t;
		}
		for(int i=0,j=0;i<=s;++i,++ans)
		{
			if(j<i)j=i;
			for(;j<=s&&a[j]==1;++j);
			if(j<=s)--a[j];
			else {ans+=(s-i+2)>>1;break;}
		}
		write(ans),putchar('\n');
	} 
	return 0;
}