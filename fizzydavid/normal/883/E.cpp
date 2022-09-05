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

int n,m,used;
char s[55],t[55];
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)if(s[i]!='*')used|=1<<s[i]-'a';
	get1(m);
	int ok=(1<<26)-1;
	for(int i=1;i<=m;i++)
	{
		scanf("%s",t+1);
		bool match=1;
		int msk=0;
		for(int j=1;j<=n;j++)
		{
			if(s[j]!='*'&&t[j]!=s[j])match=0;
			if(s[j]=='*'&&((used>>t[j]-'a')&1))match=0;
		}
		if(match)
		{
			for(int j=1;j<=n;j++)msk|=(1<<t[j]-'a');
			ok&=msk;
		}
	}
	printf("%d\n",__builtin_popcount(ok&~used));
	return 0;
}