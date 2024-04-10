#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;
const int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

char s[5000500];
int N,a[5000500];

int getTime(char s[])
{
	int m=(s[5]-'0')*10+s[6]-'0';
	int d=(s[8]-'0')*10+s[9]-'0';
	int h=(s[11]-'0')*10+s[12]-'0';
	int mi=(s[14]-'0')*10+s[15]-'0';
	int se=(s[17]-'0')*10+s[18]-'0';
	
	fr(i,1,m-1) d+=month[i];
	return d*86400+h*3600+mi*60+se;
}

void write(int t)
{
	int se=t%60; t/=60;
	int mi=t%60; t/=60;
	int h=t%24; t/=24;
	int m,d=t;
	fr(i,1,12)
		if (d>=month[i]) d-=month[i];
		else
		{
			m=i; break;
		}
	cout << "2012-" << m/10 << m%10 << '-' << d/10 << d%10 << ' ';
	cout << h/10 << h%10 << ':' << mi/10 << mi%10 << ':' << se/10 << se%10 << endl;
}

int main()
{
	int n,m;
	cin >> n >> m;
	gets(s);
	while (gets(s)) a[N++]=getTime(s);
	fr(i,m-1,N-1)
		if (a[i]-a[i-m+1]<n) 
		{
			write(a[i]);
			return 0;
		}
	puts("-1");
}