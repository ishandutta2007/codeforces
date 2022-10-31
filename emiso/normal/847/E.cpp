#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector < int > asts;

int bsearch(int x) {
    int ini = 0, fim = asts.size() - 1;
    while (ini <= fim) {
        int mid = (ini + fim) / 2;
        if (asts[mid] > x) fim = mid-1;
        else ini = mid+1;
    }
    return fim;
}

int main() {
    scanf("%d", &n);
    cin >> s;

    for (int i = 0; i < n; i++)
        if (s[i] == '*')
            asts.push_back(i);

    int ini = 1, fim = 2*n;
    while (ini <= fim) {
        int mid = (ini + fim) / 2;

        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (pos >= asts.size()) break;
            if (s[i] != 'P') continue;

            if (asts[pos] > i) {
                while (pos < asts.size() && asts[pos] - i <= mid) pos++;
            }
            else if (i - asts[pos] <= mid) {
                int x = bsearch(i + mid - 2*(i - asts[pos]));
                int y = bsearch(i + (mid - i + asts[pos]) / 2);

                if ((max(x, y) == -1? -1 : asts[max(x, y)]) < i) while (pos < asts.size() && asts[pos] < i) pos++;
                else pos = max(pos, max(x, y) + 1);
            }
        }

        if (pos >= asts.size()) fim = mid-1;
        else ini = mid+1;
    }

    printf("%d\n", ini);
    return 0;
}