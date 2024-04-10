#include<cstdio>
#include<cstring>
const int N=55;
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
int a[N],b[N],ans[N][5],s[N];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;1;++i)
	{
		int j=1;
		if(a[1]==1)
		{
			while(a[j]==j)++j;
			if(j>n)
			{
				write(i-1),putchar('\n');
				for(j=1;j<i;++j)
				{
					write(s[j]);
					for(int k=1;k<=s[j];++k)putchar(' '),write(ans[j][k]);
					putchar('\n');
				}
				return 0;
			}
			ans[i][s[i]=1]=j-1;
		}
		int k=a[j]-1;
		for(ans[i][++s[i]]=1;a[j]==a[j+1]-1;++j,++ans[i][s[i]]);
		++s[i];
		while(a[j]!=k)++j,++ans[i][s[i]];
		if(j!=n)ans[i][++s[i]]=n-j;
		j=0,k=n;
		for(int l=s[i];l;--l)
		{
			k-=ans[i][l];
			for(int r=1;r<=ans[i][l];++r)b[j+r]=a[k+r];
			j+=ans[i][l];
		}
		memcpy(a,b,sizeof a);
	}
	return 0;	
}