#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// Returns the number of pairs (i, j) such that i < j and A[i] > A[j].
// Runs in O(nlogn). Will not mutate the array.

template<typename it>
long long inversions(it first, it last) {

    typedef typename remove_reference<decltype(*first)>::type T;
    long long n = last-first, out = 0;
    vector<T> A(first, last), B(n);

    for (int w = 1; w < n; w <<= 1) {
        for (int k = 0; k < n;) {
            int s = k, j = k+w;
            for (int i = k; i < s+w && i < n; i++) {
                while (j < s+(w<<1) && j < n && A[j] < A[i])
                    B[k++] = A[j++];
                B[k++] = A[i], out += j-(s+w);
            }
            while (j < s+(w<<1) && j < n)
                B[k++] = A[j++];
        }
        swap(A, B);
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    string t = s; reverse(all(t));
    vector<int> p(n);
    for (char c = 'a'; c <= 'z'; c++) {
        int j = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == c) {
                while (t[j] != c) j++;
                p[i] = j++;
            }
    }
    debug(p);
    cout << inversions(all(p)) << "\n";
}