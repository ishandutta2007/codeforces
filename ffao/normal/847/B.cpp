#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int a[210000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    vector< vector<int> > seqs;
    seqs.push_back(vector<int>());
    seqs[0].push_back(a[0]);

    for (int i = 1; i < n; i++) {
        int st = 0, ed = seqs.size();
        while (st < ed) {
            int m = (st+ed)/2;
            if (seqs[m].back() < a[i]) ed = m;
            else st = m+1; 
        }

        if (seqs.size() == st) seqs.push_back(vector<int>());
        seqs[st].push_back(a[i]);
    }

    for (int i = 0; i < (int)seqs.size(); i++) {
        for (int x : seqs[i]) {
            cout << x;
            cout << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}