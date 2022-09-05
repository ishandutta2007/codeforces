#include <bits/stdc++.h>
using namespace std;

int n, num1, num2;
string str[210];

int main() {
    int tot = 0;
    while (cin >> str[++tot]) {
        if (str[tot] == "=") {
            cin >> n; break;
        } else if (tot == 1 || str[tot] == "+") {
            num1++;
        } else if (str[tot] == "-") {
            num2++;
        }
    }
    if (num1 * n >= num2 + n && num1 <= num2 + n) {
        puts("Possible");
        int rem = num2 + n;
        for (int i = 1; i <= tot; i++) {
            if (str[i] == "?") {
                if (i == 1 || str[i - 1] == "+") {
                    int val = max(1, rem - (num1 - 1) * n);
                    assert(val <= n);
                    str[i] = to_string(val);
                    rem -= val, num1--;
                } else {
                    str[i] = "1";
                }
            }
            cout << str[i] << " ";
        }
        cout << n << endl;
    } else if (num2 * n >= num1 - n && num2 <= num1 - n) {
        puts("Possible");
        int rem = num1 - n, tmp = 0, all = 0;
        for (int i = 1; i <= tot; i++) {
            if (str[i] == "?") {
                if (i > 1 && str[i - 1] == "-") {
                    int val = max(1, rem - (num2 - 1) * n);
                    assert(val <= n);
                    str[i] = to_string(val);
                    rem -= val, num2--;
                    all -= val;
                } else {
                    int val = min(n, tmp + 1);
                    str[i] = to_string(val);
                    tmp -= val - 1;
                    all += val;
                }
            }
            cout << str[i] << " ";
        }
        cout << n << endl;
        assert(all == n);
    } else {
        puts("Impossible");
    }
    return 0;
}
/*
? + ? + ? + ? + ? + ? + ? + ? - ? - ? + ? + ? + ? + ? + ? + ? + ? + ? + ? + ? + ? - ? + ? + ? - ? - ? + ? + ? - ? - ? + ? + ? + ? - ? - ? + ? + ? + ? + ? + ? + ? + ? + ? + ? + ? + ? + ? + ? + ? - ? + ? + ? + ? - ? + ? + ? + ? + ? + ? + ? + ? + ? + ? + ? + ? + ? - ? + ? + ? + ? + ? + ? + ? - ? + ? + ? + ? + ? + ? + ? + ? + ? + ? + ? - ? - ? + ? + ? + ? - ? + ? + ? - ? - ? + ? - ? + ? + ? + ? = 4
*/