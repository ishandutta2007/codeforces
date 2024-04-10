    #include <iostream>
    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <set>
    #include <algorithm>
    #include <string>
    #include <cstring>
    #include <cstdlib>

    using namespace std;

    int main() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 0; k > 0 && i + 1 < n; ++i) {
            if (s[i] == '4' && s[i + 1] == '7') {
                if (i % 2 == 0) {
                    if (i + 2 == n || s[i + 2] != '7') {
                        s[i + 1] = '4';
                        --k;
                    } else {
                        if (k % 2 == 1) {
                            s[i + 1] = '4';
                        }
                        k = 0;
                    }
                } else {
                    if (i == 0 || s[i - 1] != '4') {
                        s[i] = '7';
                        --k;
                    } else {
                        if (k % 2 == 1) {
                            s[i] = '7';
                        }
                        k = 0;
                    }
                }
            }
        }
        cout << s << '\n';
        return 0;
    }