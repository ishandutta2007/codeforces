// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

char s[200111];
int n,sum,dg[10000111];
bool sub[200111];
int main()
{
	for(int i=1;i<10000111;i++)dg[i]=dg[i/10]+i%10;
	get1(n);scanf("%s",s+1);
	for(int i=1;i<=n;i++)sum+=s[i]-'0';
	int cur=n-1;
	while(cur>=1&&dg[dg[sum]]>=10)
	{
		if(s[cur]=='0')cur--;
		else
		{
			sum+=9*(s[cur]-'0');
			sub[cur]=1;
			cur-=2;
		}
	}
	if(dg[dg[sum]]>=10)for(;;);
	
	for(int i=1;i<=n;i++)
	{
		putchar(s[i]);
		if(!sub[i]&&i<n)putchar('+');
	}
	puts("");
	memset(s,0,sizeof(s));
	sprintf(s+1,"%d",sum);sum=0;n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		putchar(s[i]);
		if(i<n)putchar('+');
		sum+=s[i]-'0';
	}
	puts("");
	memset(s,0,sizeof(s));
	sprintf(s+1,"%d",sum);sum=0;n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		putchar(s[i]);
		if(i<n)putchar('+');
		sum+=s[i]-'0';
	}
	puts("");
	return 0;
}