#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 500 + 13;


/*

*/


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);


    vector<int> p;
    for(int i = 2; i <= 100; i++) {
        bool fl = false;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                fl = true;
                break;
            }
        }
        if(!fl)
            p.push_back(i);
    }

    int cur = 0;
    int cnt = 0;
    for(int i = 0; i < p.size() && cur < 20; i++) {
        cout << p[i] << endl;
        string s;
        cin >> s;
        cur++;

        if(s[0] == 'y') {
            cnt++;

            if(cnt >= 2) {
                cout << "composite" << endl;
                return 0;
            }

            if(p[i] * p[i] <= 100) {
                cout << p[i] * p[i] << endl;
                cin >> s;
                cur++;
                if(s[0] == 'y') {
                    cout << "composite" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "prime" << endl;
}