#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> T gcd(T a, T b) { return b==0 ? a : gcd(b,a%b); }

const int MAXN=300010;

int a[MAXN];
LL s[MAXN];
int n;
map<int,int> h;

int main() {
	scanf("%d", &n);
	LL ans=-(LL)(1<<30)*(LL)(1<<20);
	int ansl, ansr;
	s[0]=0;
	forint(i, 1, n) {
		scanf("%d", &a[i]);
		s[i]=s[i-1]; if(a[i]>0) s[i]+=a[i];
		if(h.find(a[i])==h.end()) {
			h[a[i]]=i;
		} else {
			int j=h[a[i]];
			LL t=s[i-1]-s[j]+a[j];
			if(t+a[i]>ans) {
				ans=t+a[i];
				ansl=j; ansr=i;
			}
			if(t<0) h[a[i]]=i;
		}
	}
	VI rem;
	forint(i, 1, n) {
		if(i<ansl || i>ansr) rem.PB(i);
		else if(i>ansl && i<ansr && a[i]<0) rem.PB(i);
	}
	cout<<ans<<" "<<rem.size()<<endl;
	forn(i, rem.size()) printf("%d%c", rem[i],i<(int)rem.size()-1?' ':'\n');

	return 0;
}