#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> name, ans, a;
int curName = 0;
int n, k;

void add(int i, int n) {
    for (; i < n; i++) ans[i] = name[curName], curName++;
}

int main() {
    for (int i = 0; i < 26; i++)
        name.push_back((string) + "A" + (char) (i + 97));
    for (int i = 0; i < 26; i++)
        name.push_back((string) + "B" + (char) (i + 97));
    for (int i = 0; i < 26; i++)
        name.push_back((string) + "C" + (char) (i + 97));
    for (int i = 0; i < 26; i++)
        name.push_back((string) + "D" + (char) (i + 97));
    cin >> n >> k; a.resize(n); ans.resize(n);
    for (int i = 0; i < n - k + 1; i++)
        cin >> a[i];

    int x = 0;
    while ((x < n - k + 1) && (a[x] == "NO")) x++;
    if (x == n - k + 1) {
        for (int i = 0; i < n; i++)
            cout << "A" << " ";
        cout << endl;
        return 0;
    }
    add(x, x + k);

    for (int i = x - 1; i >= 0; i--)
        if (a[i] == "NO")
            ans[i] = ans[i + k - 1];
        else add(i, i + 1);

    for (int i = x + 1; i < n - k + 1; i++)
        if (a[i] == "NO")
            ans[i + k - 1] = ans[i];
        else add(i + k - 1, i + k);


    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}