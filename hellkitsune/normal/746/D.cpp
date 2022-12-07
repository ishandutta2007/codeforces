#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, g, b;
char ans[100005];
int ansc = 0;

void drinkB(char &was, int &cnt) {
    if (b == 0) {
        cout << "NO" << endl;
        exit(0);
    }
    --b;
    if (was == 'b') {
        ++cnt;
    } else {
        was = 'b';
        cnt = 1;
    }
    ans[ansc++] = 'B';
}

void drinkG(char &was, int &cnt) {
    if (g == 0) {
        cout << "NO" << endl;
        exit(0);
    }
    --g;
    if (was == 'g') {
        ++cnt;
    } else {
        was = 'g';
        cnt = 1;
    }
    ans[ansc++] = 'G';
}

int main() {
    cin >> n >> k >> g >> b;
    char was = '-';
    int cnt = 0;
    forn(i, n) {
        if (g > b) {
            if (was == 'g' && cnt == k) {
                drinkB(was, cnt);
            } else {
                drinkG(was, cnt);
            }
        } else {
            if (was == 'b' && cnt == k) {
                drinkG(was, cnt);
            } else {
                drinkB(was, cnt);
            }
        }
    }
    ans[n] = '\0';
    printf("%s\n", ans);
    return 0;
}