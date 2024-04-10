#include <bits/stdc++.h>
using namespace std;

map <pair <pair <int, int>, pair <int, int> >, string> mapa;
string s;
int n, m;

int main()
{
    int a, b, c, d;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        mapa [make_pair(make_pair(a, b), make_pair(c, d))] = s;
    }
    for (int j = 0; j < m; j++)
    {
        cin >> s;
        scanf("%d.%d.%d.%d;", &a, &b, &c, &d);
        cout << s << " " << a << "." << b << "." << c << "." << d << "; #" << mapa [make_pair(make_pair(a, b), make_pair(c, d))] << endl;
    }
    return 0;
}