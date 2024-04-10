#include <bits/stdc++.h>

using namespace std;

char a[9];

const array<int, 3> win_cond[] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};

bool check_win(char c) {
    for (auto &v : win_cond) {
        if (a[v[0]] == c && a[v[1]] == c && a[v[2]] == c) {
            return true;
        }
    }

    return false;
}

int main() {
    for (char &c : a) cin >> c;

    int cnt_x = count(a, a + 9, 'X');
    int cnt_o = count(a, a + 9, '0');

    bool win_x = check_win('X');
    bool win_o = check_win('0');

    if (cnt_o > cnt_x || cnt_x > cnt_o + 1 ||
            (win_x && cnt_x != cnt_o + 1) ||
            (win_o && cnt_x != cnt_o)) {
        cout << "illegal";
    } else if (win_x) {
        cout << "the first player won";
    } else if (win_o) {
        cout << "the second player won";
    } else if (cnt_x == 5) {
        cout << "draw";
    } else if (cnt_x == cnt_o) {
        cout << "first";
    } else if (cnt_x == cnt_o + 1) {
        cout << "second";
    } else {
        exit(1);
    }
}