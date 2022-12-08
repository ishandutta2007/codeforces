// 15:27
// 15:37 offline for cal2()
//
// 15:44 online
// 15:54 test sample fail
// 15:56 offline debug
//
// 16:06 pass sample
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPI;
#define MP make_pair
#define PB push_back
#define fi first
#define se second

LL len;
vector<LL> s[2];

struct Ans {
	LL v, c;
	Ans() : v(-1), c(0) {}
	void update(const Ans &a) {
		if(a.v>v) *this=a;
		else if(a.v==v) c+=a.c;
	}
};

Ans cal1(vector<LL> a) {
	int n=a.size();
	if(a.size()<3) return Ans();
	if(a[0]==a.back()) {
		LL t=n;
		Ans ans;
		ans.v=0;
		ans.c=t*(t-1)*(t-2)/6;
		return ans;
	} else {
		LL x=0, y=0;
		forn(i, a.size()) {
			if(a[i]==a[0]) ++x;
			if(a[i]==a.back()) ++y;
		}
		Ans ans;
		ans.v=(a.back()-a[0])*2;
		ans.c=0;
		forint(i, 1, x)
			ans.c+=LL(y)*LL(n-i-1+n-i-y)/2;
		return ans;
	}
}

Ans cal2(vector<LL> a, vector<LL> b) {
	int n=(int)a.size();
	if(a.size()<2 || b.size()<1) return Ans();
	vector<int> lp(a.size()), rp(a.size());
	forn(i, a.size()) {
		lp[i]=i; if(i>0 && a[i-1]==a[i]) lp[i]=lp[i-1];
	}
	forndown(i, a.size()) {
		rp[i]=i; if(i+1<(int)a.size() && a[i+1]==a[i]) rp[i]=rp[i+1];
	}
	int i=0;
	Ans ans;
	forn(j, b.size()) {
		while(i<int(a.size()) && a[i]<b[j]) ++i;
		// b <= a1 <= a2
		if(i<int(a.size())) {
			int i2=rp[i];
			Ans tmp;
			tmp.v=2*b[j]-2*a[i]+2*len;
			tmp.c=LL(n-1-i+n-1-i2)*LL(i2-i+1)/2;
			ans.update(tmp);
		}
		// a1 <= a2 < b
		if(i>0) {
			int i2=lp[i-1];
			Ans tmp;
			tmp.v=2*a[i-1]-2*b[j]+2*len;
			tmp.c=LL(i-1+i2)*LL(i-i2)/2;
			ans.update(tmp);
		}
		// a1 < b <= a2
		if(i>0 && i<int(a.size())) {
			Ans tmp;
			tmp.v=2*len;
			tmp.c=LL(i)*LL(a.size()-i);
			ans.update(tmp);
		}
	}
	return ans;
}

int main() {
	int n; 
	cin>>len>>n;
	s[0].clear();
	s[1].clear();
	forint(i, 1, n) {
		int x; LL y;
		cin>>x>>y;
		s[x].PB(y);
	}

	sort(s[0].begin(), s[0].end());
	sort(s[1].begin(), s[1].end());

	Ans ans;
	ans.update(cal1(s[0]));
	ans.update(cal1(s[1]));
	ans.update(cal2(s[0], s[1]));
	ans.update(cal2(s[1], s[0]));
	//cout<<ans.v<<endl;
	cout<<ans.c<<endl;
	return 0;
}