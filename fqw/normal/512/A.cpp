// 13:23 - 13:28
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //

int main() {
	int n; scanf("%d", &n);
	bool g[33][33]; fillchar(g, 0);
	string s="", t;
	forn(i, n) {
		cin>>t;
		size_t k=0;
		bool found=false;
		while(k<s.size() && k<t.size())
			if(s[k]!=t[k]) {
				g[s[k]-'a'][t[k]-'a']=true;
				found=true;
				break;
			} else
				++k;
		if(!found) {
			if(k<s.size()) g[1][2]=g[2][1]=true;
		}
		s=t;
	}

	int d[33]={0};
	forn(i, 26) forn(j, 26) if(g[i][j]) ++d[j];
	queue<int> q;
	forn(i, 26) if(d[i]==0) q.push(i);
	string ans="";
	while(!q.empty()) {
		int i=q.front(); q.pop();
		ans+=char('a'+i);
		forn(j, 26) if(g[i][j]) {
			--d[j];
			if(d[j]==0) q.push(j);
		}
	}
	if(ans.size()!=26) ans="Impossible";
	cout<<ans<<endl;

	return 0;
}