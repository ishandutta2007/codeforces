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

int d[10100];

int main()
{
	string s;
	getline(cin,s);
	for (int i=0;i<int(s.size());i++)
		if (s[i]==',' || s[i]=='.' || s[i]=='!' || s[i]=='?')
		{
			if (i && s[i-1]==' ') d[i-1]=1;
		}
		else
			if (s[i]==' ')
				if (i && s[i-1]==' ') d[i-1]=1;
	for (int i=0;i<int(s.size());i++)
	{
		if (d[i]==1) continue;
		cout << s[i];
		if (s[i]==',' || s[i]=='.' || s[i]=='!' || s[i]=='?')
		{
			if (i+1<s.size() && s[i+1]!=' ') cout << ' ';
		}
	}
	puts("");
}