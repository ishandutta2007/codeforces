#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
template<class T> bool setmin(T &a, T b) {
	if(b<a) {a=b; return true;} else return false;
}
template<class T> bool setmax(T &a, T b) {
	if(b>a) {a=b; return true;} else return false;
}
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))

const int MAXN=1000000+100;

char a[MAXN], b[MAXN];
int la, lb;
LL n, m;

int gcd(int a, int b) {
	return b==0 ? a : gcd(b,a%b);
}

int main() {
	cin>>n>>m;
	scanf("%s%s", a, b);
	la=strlen(a);
	lb=strlen(b);
	int p=gcd(la, lb);
	LL t=(LL)la*(LL)lb/(LL)p;
	LL mult=n*(LL)la/t;
	LL ans=t;
	forn(i, p) {
		LL cnt[26];
		fillchar(cnt, 0);
		for(int j=i; j<la; j+=p)
			cnt[a[j]-'a']++;
		LL tmp=0;
		for(int j=i; j<lb; j+=p)
			tmp+=cnt[b[j]-'a'];
		ans-=tmp;
	}
	ans*=mult;
	cout<<ans<<endl;
	return 0;
}