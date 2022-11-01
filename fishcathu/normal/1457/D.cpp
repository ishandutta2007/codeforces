#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1E5+1;
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
int a[61][61];
int main()
{
	int n=read(),ans=1<<30;
	if(n>60){puts("1");return 0;}
	for(int i=1;i<=n;++i)a[i][i]=read();
	for(int i=1;i<n;++i)for(int j=i+1;j<=n;++j)a[i][j]=a[i][j-1]^a[j][j];
	for(int i=1;i<n;++i)for(int j=i;j<n;++j)for(int k=j+1;k<=n;++k)if(a[i][j]>a[j+1][k])ans=min(ans,k-i-1);
	if(ans==1<<30)puts("-1");
	else write(ans);
	return 0;
}