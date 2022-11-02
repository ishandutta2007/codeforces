#include<cstdio>
#include<cstring>
const int N=8E5,inf=2139062143;
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
int best[N],min[N][9],p,q;
void chu(int i){best[i]=inf,memset(min[i],0x7f,36);}
void up(int x,int i){chu(i);for(int t=x,s=0;t;t/=10,++s)if(t%10)min[i][s]=x;}
void mer(int i,int l,int r)
{
	chu(i),best[i]=best[l]<best[r]?best[l]:best[r];
	for(int j=0;j<9;++j)
	{
		min[i][j]=min[l][j]<min[r][j]?min[l][j]:min[r][j];
		if(min[l][j]!=inf&&min[r][j]!=inf&&min[l][j]+min[r][j]<best[i])best[i]=min[l][j]+min[r][j];
	}
}
void build(int i,int l,int r){l!=r?build(i<<1,l,l+r>>1),build(i<<1|1,l+r+2>>1,r),mer(i,i<<1,i<<1|1):up(read(),i);}
void cha(int i,int l,int r){l!=r?l+r>>1>=p?cha(i<<1,l,l+r>>1):cha(i<<1|1,l+r+2>>1,r),mer(i,i<<1,i<<1|1):up(q,i);}
void ans(int i,int l,int r)
{
	if(l>=p&&r<=q)
	{
		if(best[i]<best[0])best[0]=best[i];
		for(int j=0;j<9;++j)if(min[i][j]!=inf&&min[0][j]!=inf&&min[i][j]+min[0][j]<best[0])best[0]=min[i][j]+min[0][j];
		for(int j=0;j<9;++j)if(min[i][j]<min[0][j])min[0][j]=min[i][j];
	}
	else
	{
		if(l+r>>1>=p)ans(i<<1,l,l+r>>1);
		if(l+r>>1<q)ans(i<<1|1,l+r+2>>1,r);
	}
}
int main()
{
	int n=read(),m=read();
	build(1,1,n);
	while(m--)
	{
		int t=read();
		p=read(),q=read();
		if(t==1)cha(1,1,n);
		else chu(0),ans(1,1,n),write(best[0]==inf?-1:best[0]),putchar('\n');
	}
	return 0;
}