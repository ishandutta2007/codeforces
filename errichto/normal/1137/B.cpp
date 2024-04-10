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

using ll = long long;

const int nax = 5e5 + 5;
char a[nax], b[nax];

// https://www.geeksforgeeks.org/longest-prefix-also-suffix/
int longestPrefixSuffix(string s) 
{ 
    int n = s.length(); 
  
    int lps[n]; 
    lps[0] = 0; // lps[0] is always 0 
  
    // length of the previous 
    // longest prefix suffix 
    int len = 0; 
  
    // the loop calculates lps[i] 
    // for i = 1 to n-1 
    int i = 1; 
    while (i < n) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider 
            // the example. AAACAAAA 
            // and i = 7. The idea is 
            // similar to search step. 
            if (len != 0) 
            { 
                len = lps[len-1]; 
  
                // Also, note that we do 
                // not increment i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1]; 
  
    // Since we are looking for 
    // non overlapping parts. 
    return res; //(res > n/2)? n/2 : res; 
} 
  

int main() {
    scanf("%s", a);
    scanf("%s", b);
    int ones = 0, zeroes = 0;
    int A = strlen(a);
    int B = strlen(b);
    for(int i = 0; i < A; ++i) {
        if(a[i] == '0') {
            ++zeroes;
        }
        else {
            ++ones;
        }
    }
    for(int i = 0; i < B; ++i) {
        if(b[i] == '0') {
            --zeroes;
        }
        else {
            --ones;
        }
    }
    if(zeroes < 0 || ones < 0) {
        printf("%s\n", a);
        return 0;
    }
    int answer = 1;
    int len = longestPrefixSuffix(string(b));
    string s = string(b);
    while(true) {
        pair<int,int> memo{zeroes, ones};
        for(int i = len; i < B; ++i) {
            if(b[i] == '0') {
                --zeroes;
            }
            else {
                --ones;
            }
        }
        if(ones < 0 || zeroes < 0) {
            for(int i = 0; i < memo.first; ++i) {
                s += '0';
            }
            for(int i = 0; i < memo.second; ++i) {
                s += '1';
            }
            printf("%s\n", s.c_str());
            return 0;
        }
        for(int i = len; i < B; ++i) {
            s += b[i];
        }
        ++answer;
    }
}