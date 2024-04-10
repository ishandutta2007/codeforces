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

int n,last,st[200200],done,wrong;
string s,ans;

int main()
{
	cin >> n;
	while (cin >> s)
	{
		if (done)
		{
			wrong=1;
			break;
		}
		
		if (s[0]=='p')
		{
			st[++last]=0;
			ans+="pair<";
		}
		else
		{
			ans+="int";
			if (!last)
			{
				if (n==1) done=1;
				else 
				{
					wrong=1;
					break;
				}
			}
			
			while (last && st[last]) last--, ans+='>';
			if (last) st[last]++, ans+=',';
		}
	}
	if (last || wrong) puts("Error occurred");
	else cout << ans << endl;
}