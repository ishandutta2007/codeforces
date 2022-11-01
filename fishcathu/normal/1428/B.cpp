#include<cstdio>
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
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),a[2]={0},ans=0;
		char c,t,k;
		while((c=getchar())!='-'&&c!='>'&&c!='<');
		if(c=='>')++a[0];
		if(c=='<')++a[1];
		if(c=='-')ans+=2,++a[0],++a[1];
		k=c;
		for(int i=n;--i;)
		{
			if((t=getchar())=='-')ans+=c=='-'?1:2,++a[0],++a[1];
			c=t;
			if(c=='>')++a[0];
			if(c=='<')++a[1];
		}
		if(k=='-'&&t=='-')--ans;
		if(a[0]==n||a[1]==n)ans=n;
		write(ans),putchar('\n');
	}
	return 0;
}