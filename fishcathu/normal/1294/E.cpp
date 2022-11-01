#include<cstdio>
#include<cstring>
const int N=2E5+10; 
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
	int n=read(),m=read(),a[n][m],sum=n*m;
	memset(a,0,sizeof a);
	for(int i=0,t;i<n;++i)for(int j=0;j<m;++j)if((t=read()-1)%m==j&&t<sum)++a[i-t/m<0?i-t/m+n:i-t/m][j];
	for(int i=0;i<m;++i)
	{
		int min=0;
		for(int j=0;j<n;++j)if(j-a[j][i]<min)min=j-a[j][i];
		sum+=min;
	}
	write(sum);
	return 0;
}