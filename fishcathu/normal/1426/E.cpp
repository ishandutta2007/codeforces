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
int a[3],b[3];
int main()
{
	read();
	int a1=0;
	long long a2=0;
	for(int i=0;i<3;++i)a[i]=read();
	for(int i=2;i<5;++i)b[i%3]=read();
	for(int i=0;i<3;++i)
	{
		int sum=a[i];
		for(int j=0;j<3;++j)if(j!=i)sum-=b[j];
		if(sum>a1)a1=sum;
		a2+=a[i]<b[i]?a[i]:b[i];
	}
	printf("%d %lld\n",a1,a2);
	return 0;
}