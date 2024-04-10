#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector <int> v(n);
    int zc = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (!v[i]) zc++;
    }
    if (v[n - 1] == 1) { cout << "NO"; return 0; }
    int k = n - 1, zae = 0;
    while (k >= 0 && v[k] == 0) k--, zae++;
    if (zae % 2 == 1)
    {
        cout << "YES" << endl << v[0];
        for (int i = 1; i < n; i++) cout << "->" << v[i];
        return 0;
    }
    if (zae == 2)
    {
        if (zc == 2) { cout << "NO"; return 0; }
        cout << "YES" << endl;
        int q;
        for (int i = 0; i < n; i++)
        {
            if (i) cout << "->";
            cout << v[i];
            if (!v[i]) { q = i; break; }
        }
        cout << "->(";
        for (int i = q + 1; i < n - 1; i++)
        {
            if (i != q + 1) cout << "->";
            cout << v[i];
        }
        cout << ")->" << v[n - 1];
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i <= k; i++)
    {
        if (i) cout << "->";
        cout << v[i];
    }
    if (k >= 0) cout << "->";
    cout << v[k + 1] << "->(" << v[k + 2];
    for (int i = k + 3; i < n - 1; i++) cout << "->" << v[i];
    cout << ")->" << v[n - 1];


}