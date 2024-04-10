#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Fenwick {
    private:
        vector <long long> v;
        int n;
    public:
        inline void modify(int i, long long delta) {
            for (; i < n; i |= i+1)
                v[i] += delta;
        }

        inline long long sum(int i) {
            long long sum = 0;
            for (; i >= 0; i &= i+1, i--)
                sum += v[i];
            return sum;
        }

        inline long long sum(int l, int r) {
            return sum(r) - sum(l-1);
        }

        inline Fenwick(int n)
            : v(n), n(n) {
        }
};

inline long long sumInversionSegments(const vector<int>& v) {
    Fenwick f(v.size());
    long long res = 0;
    int frontAdd = 1, backAdd = v.size();
    for_each(v.rbegin(), v.rend(), [&](int it){
        res += backAdd * f.sum(it);
        f.modify(it, frontAdd);
        frontAdd++; backAdd--;
    });
    return res;
}

inline long long inversions(const vector<int>& v) {
    Fenwick f(v.size());
    long long res = 0;
    for_each(v.rbegin(), v.rend(), [&](int it){
        res += f.sum(it);
        f.modify(it, 1);
    });
    return res;
}

inline long long segmentCount(int n) {
    return (long long)n * (n + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector <int> v;
    generate_n(back_inserter(v), n, [&](){
        int x; cin >> x;
        return x-1;
    });
    long long cnt = segmentCount(n);
    long double sum = (long double)cnt * inversions(v);
    sum -= sumInversionSegments(v);
    for (int i = 0; i < n; i++)
        sum += (long double)(n - i) * segmentCount(i) * 0.5;
    long double res = sum / cnt;
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}