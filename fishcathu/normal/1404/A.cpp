#include<cstdio>
#include<algorithm>
const int N=3E5+10;
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
char a[N];
int main()
{
    for(int x=read();x--;)
    {
    	int n=read(),m=read(),zer=0,one=0,k=0;
    	while((a[0]=getchar())<48);
    	for(int i=1;i<n;++i)a[i]=getchar();
    	for(int i=0;i<m;++i)
    	{
    		char c=-1;
    		for(int j=i;j<n;j+=m)
    		{
    			if(a[j]=='0')
    			{
    				if(c==1)k=1;
    				c=0;
				}
				else if(a[j]=='1')
				{
					if(c==0)k=1;
					c=1;
				}
			}
			if(~c)++(c?one:zer);
		}
		if(k||zer*2>m||one*2>m)puts("NO");
		else puts("YES");
	}
}