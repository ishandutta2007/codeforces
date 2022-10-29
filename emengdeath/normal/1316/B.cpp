#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int T;
    string s;
    cin>>T;
    while (T --) {
        int n;
        cin>>n;
        cin >> s;
        string ans = s;
        int ansx = 1;
        for (int i = 2; i <= n; i ++) {
            string tmp = s.substr(0, i- 1);
            string tmp1 = s.substr(i - 1, n - (i -1));
            if ((n - (i - 1)) & 1)
                reverse(tmp.begin(), tmp.end());
            tmp1 += tmp;
            if (tmp1 < ans)
                ans = tmp1, ansx = i;
        }
        cout<< ans << endl << ansx << endl;
    }
}