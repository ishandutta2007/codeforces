#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector <string> v(n);
    bool yes = false;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (!yes && v[i].substr(0, 2) == "OO") v[i][0] = v[i][1] = '+', yes = true;
        if (!yes && v[i].substr(3, 2) == "OO") v[i][3] = v[i][4] = '+', yes = true;
    }
    if (yes)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) cout << v[i] << endl;
    }
    else cout << "NO" << endl;
}