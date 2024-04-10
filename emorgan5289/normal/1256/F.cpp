#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

template<typename T>
int sub_inversions(vector<T>& A, vector<T>& store, int lower, int upper) {

    if (lower == upper) return 0;
    int mid = (lower+upper)/2;
    int out = sub_inversions(store, A, lower, mid) + sub_inversions(store, A, mid+1, upper);

    // merge sort
    int j = mid+1, k = lower;
    for (int i = lower; i <= mid; i++) {
        while (j <= upper && A[j] < A[i])
            store[k++] = A[j++];
        store[k++] = A[i];
        out += j-mid-1;
    }
    while (j <= upper)
        store[k++] = A[j++];

    return out;
}

template<typename T>
int inversions(vector<T>& A) {
    vector<T> copy(A), store(A);
    return sub_inversions(copy, store, 0, A.size()-1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int q; fin >> q;
    while (q--) {
        int n; fin >> n;
        string s, t; fin >> s >> t;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            a[i] = s[i]-'a';
            b[i] = t[i]-'a';
        }
        vector<int> as(26), bs(26);
        for (int i = 0; i < n; i++) {
            as[a[i]]++; bs[b[i]]++;
        }
        bool valid = 1;
        for (int i = 0; i < 26; i++)
            if (as[i] != bs[i]) valid = 0;
        if (!valid) {
            cout << "NO\n"; continue;
        }
        if ((inversions(a)&1) != (inversions(b)&1))
            valid = 0;
        for (int i = 0; i < 26; i++)
            if (as[i] > 1)
                valid = 1;
        // debug(inversions(a), inversions(b));
        cout << (valid ? "YES\n" : "NO\n");
    }
}