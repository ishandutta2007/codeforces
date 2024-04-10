#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

ll t, n, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    while(t--) {
		scanf("%s", s); str = s; string tmp = str;

		vector<int> f(256), rf(256); string ord; int diff = 0;
		for(char c : str) if(++f[c] == 1) diff++;
		
		int ok = 1, sz = diff;
		while(ok && !tmp.empty()) {
			char nxt = tmp.back();
			ord += nxt;
			if(f[nxt] % sz) ok = 0;
			else {
				rf[nxt] = f[nxt] / sz;
				string tmp2;
				for(char c : tmp) if(c != nxt) tmp2 += c;
				tmp = tmp2;
				sz--;
			}
		}
		if(sz || !tmp.empty()) ok = 0;
		string ans;
		if(ok) {
			for(char c : str) {
				if(sz == diff || !ok) break;
				rf[c]--;
				if(rf[c] == 0) sz++;
				if(rf[c] < 0) ok = 0;
				ans += c;
			}
		}
		if(ok) {
			for(int i = diff - 1; i >= 0; i--) {
				for(char c : ans) if(f[c]) tmp += c;
				f[ord[i]] = 0;
			}
			if(tmp != str) ok = 0;
		}

		if(!ok) puts("-1");
		else {
			printf("%s %s\n", ans.c_str(), string(ord.rbegin(), ord.rend()).c_str());
		}
    }
    return 0;
}