#include<cstdio>
#include<algorithm>
#include<cstring>
const int N=100000;
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
	for(int x=read();x--;)
	{
		memset(a,0,sizeof a),a[0]=1;
		int n=read(),m=read(),s=0,z=0,t=0;
		char c;
		while((c=getchar())<=32);
		for(int i=n;i--;c=getchar())
		{
			if(c=='W')
			{
				++s;
				if(a[t])++t; 
			}
			else ++a[t],++z;
		}
		if(t>1)std::sort(a+1,a+t);
		if(m>z)write((n<<1)-1),putchar('\n');
		else if(m==0&&s==0)puts("0");
		else
		{
			int i=1;
			for(int j=m;i<t&&j>=a[i];++i)j-=a[i];
			if(t==0)i=0;
			write(((m+s)<<1)-t+i-1),putchar('\n');
		}
	} 
	return 0;
}