#include<cstdio>
#include<algorithm>
const int N=1E5+1;
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
struct num
{
    int x,i;
    bool operator<(const num m)const
    {
    	return x<m.x;
	}
}a[N*6];
int f[N];
int main()
{
    int b[6];
    for(int i=0;i<6;++i)b[i]=read();
    int n=read();
	int min=1<<30;
    for(int i=0;i<n;++i)
    {
    	int t=read();
    	for(int j=0;j<6;++j)
    	{
        	a[i*6+j].x=t-b[j];
        	a[i*6+j].i=i;
        }
    }
    std::sort(a,a+n*6);
    for(int l=0,r=-1,sum=0;r<n*6;)
    {
    	if(sum!=n){if(!f[a[++r].i]++)++sum;}
    	else
    	{
    		if(a[r].x-a[l].x<min)min=a[r].x-a[l].x;
    		if(!--f[a[l++].i])--sum;
		}
	}
    write(min);
    return 0;
}