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
#define oo 1000111222
#define maxN 1
using namespace std;
const string type[]={"aaaa","aabb","abab","abba"};

int n,k,d[4][4],cnt[4];
string a[4];

int isVowel(char c)
{
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int match(string s,string t)
{
	int K=k,i=sz(s)-1,j=sz(t)-1;
	while (i>=0 && j>=0 && K)
	{
		if (s[i]!=t[j]) return 0;
		if (isVowel(s[i])) K--;
		i--; j--;
	}
	return !K;
}

int main()
{
	cin >> n >> k;
	rep(i,n)
	{
		rep(j,4) cin >> a[j];
		rep(j,4)
			fr(jj,j+1,3)	
				d[j][jj]=match(a[j],a[jj]);
		int s=-1;
		if (d[0][1] && d[0][2] && d[0][3]) s=0;
		else
			if (d[0][1] && !d[0][2] && d[2][3]) s=1;
			else
				if (d[0][2] && !d[0][1] && d[1][3]) s=2;
				else
					if (d[0][3] && !d[0][1] && d[1][2]) s=3;
		if (s<0)
		{
			puts("NO");
			return 0;
		}
		cnt[s]++;
	}
	int dif=0;
	fr(i,1,3) dif+=(cnt[i]>0);
	if (dif>1) puts("NO");
	else
	{
		if (!dif) puts("aaaa");
		else 
			fr(i,1,3)
				if (cnt[i])
					cout << type[i] << endl;
	}
}