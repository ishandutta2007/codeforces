#include <iostream>
#include <vector>

using namespace std;
#define int long long
#define double long double

vector <int> a, pref;

int getp(int p) {
    if (p == -1) return 0;
    else return pref[p];
}

double get(int len, int last) {
    int p = getp(len - 1);
    return (double) (p + last) / (double) (len + 1);
}

signed main() {
    cout.precision(20);
    ios_base::sync_with_stdio(false) ;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            a.push_back(x);
            if (pref.size() == 0) pref.push_back(x);
            else pref.push_back(pref[pref.size() -  1] + x);
       } 
       else {
            int last = a[a.size() -  1];
            int l = -1;
            int r = a.size() - 1;
            while (l < r - 1) {
                int m = (l + r) / 2;
                if (get(m + 1, last) < get(m, last)) {
                    l = m;
                } 
                else {
                    r = m;
                } 
            } 
            if (l == -1) cout << "0.0" << '\n';
            else cout << (double) (last - (double) (pref[l] + last) / (l + 2)) << '\n' ;
       } 
   } 

    return 0;
}