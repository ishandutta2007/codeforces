#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s; fin >> s;
    int x = 0, y = 0;
    vector<string> vx = {"1 1", "1 3"}, vy = {"3 1", "3 2", "3 3", "3 4"};
    for (char c : s) {
        if (c == '1') {
            cout << vx[x%2] << "\n";
            x++;
        } else {
            cout << vy[y%4] << "\n";
            y++;
        }
    }
}