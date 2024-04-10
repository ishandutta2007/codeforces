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
#define pii pair<int,int>
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000111222
#define maxN 1
using namespace std;

int n,m,a[1010][1010],r[1010],c[1010];
char s[20];

int main()
{
	int q,x,y;
	cin >> m >> n >> q;
	fr(i,1,m) fr(j,1,n) scanf("%d",a[i]+j);
	fr(i,1,m) r[i]=i;
	fr(i,1,n) c[i]=i;
	
	while (q--)
	{
		char ch;
		gets(s);
		scanf("%c%d%d",&ch,&x,&y);
		if (ch=='g') printf("%d\n",a[r[x]][c[y]]);
		else
			if (ch=='r') swap(r[x],r[y]);
			else swap(c[x],c[y]);
	}
}