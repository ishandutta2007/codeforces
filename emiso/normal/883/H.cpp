#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int cnt[300];

int main() {
    scanf("%d", &n);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        cnt[s[i]]++;

    vector < int > even, odd;

    for (int i = 0; i < 300; i++) {
        if (cnt[i] == 0) continue;
        if (cnt[i] % 2) {
            odd.push_back(i);
            cnt[i]--;
            if (cnt[i]) even.push_back(i);
        }
        else even.push_back(i);
    }

    if (odd.size() == 0) {
        printf("1\n");
        string out = "";
        for (int i = 0; i < even.size(); i++)
            for (int j = 0; j < cnt[even[i]] / 2; j++)
                out += (char)even[i];

        cout << out;
        reverse(out.begin(), out.end());
        cout << out << endl;
        return 0;
    }

    for (int i = odd.size(); i <= n; i++)
        if (n % i == 0 && ((n / i) % 2)) {
            printf("%d\n", i);
            vector < string > ws;

            for (int j = 0; j < i; j++) {
                string aux = "";
                for (int k = 0; k < n / i / 2; k++) {
                    aux += (char)even.back();
                    cnt[even.back()] -= 2;
                    if (cnt[even.back()] == 0) even.pop_back();
                }
                if (!odd.empty()) {
                    aux += (char)odd.back();
                    odd.pop_back();
                }
                else {
                    aux += (char)even.back();
                    odd.push_back(even.back());
                    cnt[even.back()] -= 2;
                    if (cnt[even.back()] == 0) even.pop_back();
                }

                for (int k = n / i / 2 - 1; k >= 0; k--)
                    aux += aux[k];

                ws.push_back(aux);
            }

            for (int j = 0; j < ws.size(); j++) {
                if (j) printf(" ");
                cout << ws[j];
            }
            printf("\n");
            break;
        }

    return 0;
}