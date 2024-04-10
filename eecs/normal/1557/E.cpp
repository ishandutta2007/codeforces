#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    cin >> T;
    while (T--) {
        string str;
        int x = 1, y = 1, cnt = 0;
        cout << x << " " << y++ << endl;
        cin >> str;
        if (str == "Done") continue;
        while (1) {
            cout << x << " " << y << endl;
            cin >> str;
            if (str == "Done") break;
            if (str == "Left" || str == "Right") {
                if (cnt > 16) cnt = 0, x++;
                else y = y % 8 + 1, cnt++;
            }
            if (str[0] == 'D') cnt = 0, x++;
            if (str[0] == 'U') y = y % 8 + 1, cnt = 1;
        }
    }
    return 0;
}