#include <iostream>
#include <vector>
#include <map>

using namespace std;

int mp[1000], u[1000];
int uc = 0;

int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector <int> v(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> v[i];
        v[i] = v[i] % m;
    }
    for (int i = 0; i < n; i++)
    {
        uc = 0;
        for (int j = 0; j < m; j++) if (mp[j]) u[uc++] = j;
        for (int j = 0; j < uc; j++) mp[(u[j] + v[i]) % m] = true; 
        mp[v[i]] = true;
        if (mp[0]) break;
    }
    if (mp[0]) cout << "YES"; else cout << "NO";
}