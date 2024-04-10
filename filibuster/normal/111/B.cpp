#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int A = 513;


/*
*/

vector<int> a[N];
int lst[N];

int main() {
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            a[j].push_back(i);
        }
        lst[i] = -INF;
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

//        cout << a[x].size() << endl;

        int res = 0;
        for(auto z : a[x]) {
            if(lst[z] + y < i) {
                res++;
            }
            lst[z] = i;
        }

        cout << res << '\n';
    }
}