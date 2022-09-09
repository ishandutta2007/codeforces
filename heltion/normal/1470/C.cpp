#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int debug = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mt19937 gen;
    gen.seed(time(nullptr));
    int n, k, p;
    cin >> n >> k;
    if(debug) cin >> p;
    vector<int> a(n, k);
    vector<int> pss(n, 1);
    for(int i = 0; i < 1000; i += 1){
        vector<int> imp;
        for(int i = 0; i < n; i += 1) if(pss[i]) imp.push_back(i);
        int x = 0;
        if(imp.empty() or (i & 1)) x = gen() % n;
        else x = imp[gen() % imp.size()];
        cout << "? " << x + 1 << endl;
        int r;
        if(debug) r = a[(x + n - (p - 1)) % n];
        else cin >> r;
        for(int i = 0; i < n; i += 1) if(a[(x + n - i) % n] != r) pss[i] = 0;
        if(count(pss.begin(), pss.end(), 1) == 1){
            if(debug) cout << i << endl;
            cout << "! " << max_element(pss.begin(), pss.end()) - pss.begin() + 1 << endl;
            return 0;
        }
        vector<int> b(n);
        b[1] = a[0];
        for(int i = 1; i < n; i += 1){
            b[i - 1] += a[i] / 2;
            b[(i + 1) % n] += (a[i] + 1) / 2;
        }
        swap(a, b);
    }
    assert(0);
    return 0;
}