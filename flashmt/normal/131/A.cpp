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
#define maxN 1
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
#define oo 1000111222
using namespace std;

int n;

int main()
{
	string s;
	int x=-1;
	cin >> s;
	rep(i,sz(s))
		if (s[i]>='a' && s[i]<='z') x=i;
	if (x>0) cout << s;
	else
		rep(i,sz(s))
			cout << char(s[i]>='a' && s[i]<='z'?s[i]-'a'+'A':s[i]-'A'+'a');
	cout << endl;
}