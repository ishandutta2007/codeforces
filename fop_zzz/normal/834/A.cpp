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
char s[22];
int mp[2001];
int n;
int main()
{
	scanf("%c %c",&s[1],&s[2]);
	mp['^']=0;mp['>']=1;mp['v']=2;mp['<']=3;
	n=read();n%=4;
	int ks=mp[s[1]],ed=mp[s[2]];
	int ans=0;
	if((ks+n)%4==ed)	ans++;
	if((ed+n)%4==ks)	ans+=2;
	if(ans==0||ans==3)	puts("undefined");
	if(ans==1)	puts("cw");
	if(ans==2)	puts("ccw");
}