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

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	sort(s.begin(),s.begin()+n);
	sort(s.begin()+n,s.begin()+n*2);
	int x=0;
	rep(i,n) x|=(s[i]==s[i+n]?1:(s[i]>s[i+n]?2:4));
	puts(x==2 || x==4?"YES":"NO");
}