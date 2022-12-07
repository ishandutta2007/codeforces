#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[100005];

int main() {
    scanf("%d%s", &n, s);
    int win = 0, lose = 0;
    forn(i, n) {
        if (s[i] == 'A') {
            ++win;
        } else {
            ++lose;
        }
    }
    if (win > lose) {
        cout << "Anton" << endl;
    } else if (win < lose) {
        cout << "Danik" << endl;
    } else {
        cout << "Friendship" << endl;
    }
    return 0;
}