#include<cstdio>
#include<cstring> 
#include<algorithm>
const int N=1E5+10;
int read() 
{ 	
	int a; 
    scanf("%d",&a);
	return a; 
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
	for(int x=read();x--;)
	{
		memset(a,0,sizeof a);
		int n=read(),m=read(),s;
		char l,r;
		while((l=getchar())!=48&&l!=49);
		l==48?s=0:s=1;
		while((r=getchar())==48||r==49)
		{
			if(r==48)++a[s];
			else if(l==48)++s;
			l=r;
		}
		--s;
		if(s==-1){puts("0");continue;} 
		std::sort(a+1,a+1+s);
		int ans=n*(s+1);
		for(int i=1;i<=s;++i)if(m*a[i]<n)ans-=n,ans+=m*a[i];
		printf("%d\n",ans);
	} 
}