#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1001;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
int a[N*N][3],ans[N][N],key[3],add[3];
char b[100010];
int main()
{
	for(int x=read();x--;)
	{
		for(int i=0;i<3;++i)key[i]=i,add[i]=0;
		int n=read(),m=read();
		for(int i=0,cnt=0;i<n;++i)for(int j=0;j<n;++j)
		{
			a[++cnt][0]=i;
			a[cnt][1]=j;
			a[cnt][2]=read()-1;
		}
		scanf("%s",b+1);
		for(int i=1;i<=m;++i)
		{
			if(b[i]=='R')++add[1];
			else if(b[i]=='L')add[1]+=n-1;
			else if(b[i]=='D')++add[0];
			else if(b[i]=='U')add[0]+=n-1;
			else if(b[i]=='I')swap(key[1],key[2]),swap(add[1],add[2]);
			else swap(key[0],key[2]),swap(add[0],add[2]);
		}
		for(int i=n*n;i>=1;--i)
		{
			ans[(a[i][key[0]]+add[0])%n][(a[i][key[1]]+add[1])%n]=(a[i][key[2]]+add[2])%n;
		}
		for(int i=0;i<n;++i)for(int j=0;j<n;++j)write(ans[i][j]+1),putchar(j==n-1?'\n':' ');
	}
}