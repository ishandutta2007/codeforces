#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

char s[2000011], t[2000011];
int c[4];
int a[2];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    scanf("%d", &N);
    scanf("%s", s);
    scanf("%s", t);
    
    for (int i = 0; i < 2 * N; ++i) {
        ++c[(s[i] - '0') * 2 + t[i] - '0'];
    }

    for (int i = 0; i < 2 * N; ++i) {
        if (c[3]) {
            ++a[i % 2];
            --c[3];
            continue;
        }
        if (c[2 - i % 2]) {
            ++a[i % 2];
            --c[2 - i % 2];
            continue;
        }
        if (c[1 + i % 2]) {
            --c[1 + i % 2];
            continue;
        }
        break;
    }
    if (a[0] > a[1]) {
        cout << "First\n";
    } else {
        if (a[1] > a[0]) {
            cout << "Second\n";
        } else {
            cout << "Draw\n";
        }
    }
	return 0;
}