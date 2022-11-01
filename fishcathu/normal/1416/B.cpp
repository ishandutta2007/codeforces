#include<cstdio>
#include<algorithm>
const int N=1E4+10;
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
int a[N],from[N*3],to[N*3],val[N*3],s;
void add(int l,int r,int v){from[++s]=l,to[s]=r,val[s]=v,a[l]-=l*v,a[r]+=l*v;}
int main()
{
    for(int x=read();x--;)
    {
    	s=0;
    	int n=read(),k=0;
    	for(int i=1;i<=n;++i)k+=a[i]=read();
    	if(k%n){puts("-1");continue;}
    	else k/=n;
    	for(int i=2;i<=n;++i)add(1,i,i-(a[i]%i?a[i]%i:i)),add(i,1,a[i]/i);
    	for(int i=2;i<=n;++i)add(1,i,k);
    	printf("%d\n",s);
    	for(int i=1;i<=s;++i)printf("%d %d %d\n",from[i],to[i],val[i]);
	}
	return 0;
}