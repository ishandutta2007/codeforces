#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

char s[9];

int main()
{
    int bl = 0, wh = 0;
    for (int j = 0; j < 8; ++j) {
        cin >> s;
        for (int i = 0; i < 8; ++i) {
            bool black = false;
            if (s[i] >= 'a') black = true, s[i] -= 32;
            int cur = 0;
            if (s[i] == 'Q') cur = 9;
            else if (s[i] == 'R') cur = 5;
            else if (s[i] == 'B' || s[i] == 'N') cur = 3;
            else if (s[i] == 'P') cur = 1;
            if (black) bl += cur;
            else wh += cur;
        }
    }
    if (bl > wh) cout << "Black";
    else if (bl < wh) cout << "White";
    else cout << "Draw";

    return 0;
}