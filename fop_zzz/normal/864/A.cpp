#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define ll long long
#define N 1020
#define lson x*2
#define rson x*2+1
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
#define clr(x, c) memset(x, c, sizeof(x))
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");};
inline void write_p(ll x){write(x);putchar(' ');}
int n,a[105],cnt[105];
int main(){
    n=read();
    For(i,1,n)
    {
    	a[i]=read(); cnt[a[i]]++;
	}
	For(i,1,n)
	{
		if(cnt[a[i]]!=n/2){
			puts("NO"); return 0;
		}
	}
	puts("YES");
	write(a[1]); putchar(' ');
	For(i,1,n)if(a[i]!=a[1]){
		write(a[i]); return 0;
	} 
}