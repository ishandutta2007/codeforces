#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s[333];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    
    set <char> diagonals, others;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && i + j != n - 1) others.insert(s[i][j]);
            else diagonals.insert(s[i][j]);
            
    cout << (others.size() == 1 && diagonals.size() == 1 && *others.begin() != *diagonals.begin() ? "YES" : "NO") << endl;
}