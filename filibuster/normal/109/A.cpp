#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int A = 513;

int di[] = {0, 1, -1, 0};
int dj[] = {1, 0, 0, -1};
/*
*/

mt19937 rnd(0);



int main() {
    int n;
    cin >> n;

    for(int i = n / 7; i >= 0; i--) {
        if((n - i * 7) % 4 == 0) {
            for(int j = 0; j < (n - i * 7) / 4; j++)
                cout << 4;
            for(int j = 0; j < i; j++)
                cout << 7;
            cout << endl;
            return 0;
        }
    }
    cout << -1;
}