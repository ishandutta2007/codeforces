#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000001
#define mod 1000000009
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)

multiset<int>H,W;
multiset<int>hl,wl;
int h,w,q;

int main()
{
	cin >> w >> h >> q;
	H.insert(0); H.insert(h); hl.insert(h);
	W.insert(0); W.insert(w); wl.insert(w);
	for(int i=0;i<q;i++)
	{
		string x; int a; cin >> x >> a;
		if(x == "H")
		{
			multiset<int>::iterator it=H.upper_bound(a);
			multiset<int>::iterator it2 = it; it2--;
			hl.erase(hl.find(*it - *it2));
			hl.insert(a - *it2);
			hl.insert(*it - a);
			H.insert(a);
		}
		else
		{
			multiset<int>::iterator it=W.upper_bound(a);
			multiset<int>::iterator it2 = it; it2--;
			wl.erase(wl.find(*it - *it2));
			wl.insert(a - *it2);
			wl.insert(*it - a);
			W.insert(a);
		}
		printf("%lld\n",1LL*(*hl.rbegin())*(*wl.rbegin()));
	}
}