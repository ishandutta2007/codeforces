#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

const LL mod = 1000000007;

string s;
int n[3];

int main()
{
    cin >> s;
    int val = 0;
    FOR (i,0,s.size())
    {
        int t = s[i]-'a';
        if (t < val)
        {
            cout << "NO";
            return 0;
        }
        val = t;
        n[val]++;
    }
    if (n[0] == 0 || n[1] == 0 || n[2] == 0)
    {
        cout << "NO";
        return 0;
    }
    if (n[2] != n[1] && n[2] != n[0])
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}