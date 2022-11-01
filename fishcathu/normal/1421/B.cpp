#include<cstdio>
const int N=300;
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
char a[N][N];
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),b[4][2]={1,2,2,1,n,n-1,n-1,n};
		for(int i=1;i<=n;++i)for(int j=1;j<=n;j++)while((a[i][j]=getchar())<48);
		int i,j;
		for(i=0;i<=1;++i)
		{
			for(j=2;j<=3&&a[b[i][0]][b[i][1]]==a[b[j][0]][b[j][1]];++j);
			if(j<=3)break;
		}
		if(i>1)printf("2\n1 2\n2 1\n");
		else
		{
			int k=0,c[2];
			if(a[b[i][0]][b[i][1]]!=a[b[i^1][0]][b[i^1][1]])c[k++]=i^1;
			if(a[b[j][0]][b[j][1]]!=a[b[j^1][0]][b[j^1][1]])c[k++]=j^1;
			printf("%d\n",k);
			for(i=0;i<k;++i)printf("%d %d\n",b[c[i]][0],b[c[i]][1]);
		}
	}
}