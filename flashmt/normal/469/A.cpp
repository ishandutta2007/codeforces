#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p, x;
    set <int> s;
    cin >> n;
    for (int i = 0; i < 2; i++)
    {
        cin >> p;
        while (p--)
        {
            cin >> x;
            s.insert(x);
        }
    }
    
    cout << (s.size() == n ? "I become the guy." : "Oh, my keyboard!") << endl;
}