#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = false;
    for (int i = 0; i < n; i++){
        for (int j = 1; i + 4 * j < n; j++){
            bool qw = true;
            for (int ij = 0; ij <= 4; ij++)
                qw &= (s[i + ij * j] == '*');
            ok |= qw;
        }
    }
    cout << (ok ? "yes" : "no") << "\n";

    return 0;
}