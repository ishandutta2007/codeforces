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

pair <string,int> a[1111],b[1111];
map <string,string> ans;
set <string> player;

int main()
{
	int n;
	cin >> n;
	rep(i,n) cin >> a[i].fi >> a[i].se;
	sort(a,a+n);
	int m=1;
	b[0]=a[n-1];
	repp(i,n-1)
		if (a[i].fi!=b[m-1].fi) b[m++]=a[i];
	n=m;
	
	cout << n << endl;
	rep(i,n)
	{
		int score=b[i].se;
		string name=b[i].fi;
		int worse=0;
		rep(j,n) 
			if (score<b[j].se) worse++;
		if (worse*100>n*50) ans[name]="noob";
		else
			if (worse*100>n*20) ans[name]="random";
			else
				if (worse*100>n*10) ans[name]="average";
				else
					if (worse*100>n) ans[name]="hardcore";
					else ans[name]="pro";
	}
	for (map <string,string>::iterator it=ans.begin();it!=ans.end();it++)
		cout << it->fi << ' ' << it->se << endl;
}