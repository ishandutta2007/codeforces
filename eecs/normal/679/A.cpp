#include <bits/stdc++.h>
using namespace std;

bool p[110], chk[110];

int main() {
    vector<int> V;
    for (int i = 2; i <= 100; i++) if (!p[i]) {
        V.push_back(i);
        for (int j = i + i; j <= 100; j += i) p[j] = 1;
    }
    vector<int> V2;
    for (int x : V) {
        if (x <= 50) V2.push_back(x);
        if (x * x <= 50) V2.push_back(x * x);
    }
    fill(chk + 2, chk + 101, 1);
    int cnt = 0;
    for (int i = 0; i < V2.size(); i++) {
        cout << V2[i] << endl;
        string s; cin >> s;
        if (s == "yes") {
            for (int j = 2; j <= 100; j++) {
                if (j % V2[i]) chk[j] = 0;
            }
        } else {
            for (int j = 2; j <= 100; j++) {
                if (!(j % V2[i])) chk[j] = 0;
            }
        }
    }
    for (int i = 2; i <= 100; i++) if (chk[i] && p[i]) {
        cout << "composite" << endl; exit(0);
    }
    cout << "prime" << endl;
    return 0;
}