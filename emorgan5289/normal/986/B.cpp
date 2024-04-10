#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
long long sub_inversions(vector<T>& A, vector<T>& store, int lower, int upper) {

    if (lower == upper) return 0;
    int mid = (lower+upper)/2;
    long long out = sub_inversions(store, A, lower, mid) + sub_inversions(store, A, mid+1, upper);

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
long long inversions(vector<T>& A) {
    vector<T> copy(A), store(A);
    return sub_inversions(copy, store, 0, A.size()-1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    cout << ((inversions(a)+n)&1 ? "Um_nik" : "Petr") << "\n";
}