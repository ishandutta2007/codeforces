#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

vector<int> m, M;
int z[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int n;

int main()
{
    FOR (i,0,7)
    {
        FOR (j,0,12)
        {
            m.push_back(z[j]+(i%10==2 && j==1));
        }
    }
    cin >> n;
    FOR (i,0,n)
    {
        int a;
        cin >> a;
        M.push_back(a);
    }
    FOR (i,0,m.size())
    {
        bool ok = 1;
        FOR (j,0,M.size())
        {
            if (j+i >= m.size() || M[j] != m[j+i])
                ok = 0;
        }
        if (ok)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}