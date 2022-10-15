#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s);i--)

#define forall(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define dforall(it,c) for(__typeof((c).rbegin()) it = (c).rbegin(); it != (c).rend(); it++)

#define esta(x,c) ((c).find(x) != (c).end())
#define all(c) (c).begin(),(c).end()

int main()
{
	#ifdef ACMTUYO
		freopen("entrada.in","r",stdin);
	#endif
	string s;
	cin >> s;
	vector<char> res;
	forall(c,s)
	{
		if (!res.empty() && res.back() == *c)
			res.pop_back();
		else
			res.push_back(*c);
	}
	forall(c,res)
		cout << *c;
	cout << endl;
	return 0;
}