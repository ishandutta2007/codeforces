#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const char *names[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};

int a[6];
int n;
string q[200000];
string ans[200000];

void solve(int v1, int v2)
{
    string sz = names[v1];
    if (v1 != v2) sz += ",", sz += names[v2];
    for (int i = 0; i < n; i++)
    {
        if (q[i] != sz) continue;
        if (a[v1])
        {
            a[v1]--;
            ans[i] = names[v1];
        }
        else if (a[v2])
        {
            a[v2]--;
            ans[i] = names[v2];
        }
        else
        {
            cout << "NO" << endl;
            exit(0);
        }
    }
}

int main()
{
    for (int i = 0; i < 6; i++) cin >> a[i];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    for (int i = 0; i < 6; i++)
    {
        solve(i, i);
        if (i != 5) solve(i, i+1);
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << ans[i] << endl;
    return 0;
}