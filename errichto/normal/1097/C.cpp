#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

const int nax = 1e6 + 5;
char sl[nax];

int main() {
	int n;
    scanf("%d", &n);
    vector<int> starty, endy;
    int zeroes = 0;
    for(int rep = 0; rep < n; ++rep) {
        scanf("%s", sl);
        int len = strlen(sl);
        int pref = 0;
        for(int i = 0; i < len; ++i) {
            if(sl[i] == '(') {
                ++pref;
            }
            else {
                --pref;
            }
            if(pref < 0) {
                break;
            }
        }
        if(pref > 0) {
            starty.push_back(pref);
        }
        if(pref == 0) {
            ++zeroes;
        }
        reverse(sl, sl + len);
        pref = 0;
        for(int i = 0; i < len; ++i) {
            if(sl[i] == ')') {
                ++pref;
            }
            else {
                --pref;
            }
            if(pref < 0) {
                break;
            }
        }
        if(pref > 0) {
            endy.push_back(pref);
        }
    }
    int answer = zeroes / 2;
    sort(starty.begin(), starty.end());
    sort(endy.begin(), endy.end());
    int i = 0;
    for(int x : endy) {
        while(i < (int) starty.size() && starty[i] < x) {
            ++i;
        }
        if(i < (int) starty.size() && starty[i] == x) {
            ++i;
            ++answer;
        }
    }
    printf("%d\n", answer);
}