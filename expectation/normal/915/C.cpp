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

string a, b;
string ans;
bool same = true;

bool cando(int pos1, int pos2)
{
    if (!same) return true;
    if (a[pos2] < b[pos1]) {same = false; return true; }
    if (a[pos2] > b[pos1]) return false;
    string c = a;
    c[pos2] = '0'-1;
    sort(c.begin(),c.end());
    //cout << c <<" "<<pos1+1<<endl;
    FOR (j,pos1+1,c.size())
    {
        if (c[j] != b[j])
            return c[j] < b[j];
    }
    return true;
}

void backntr(int pos)
{
    FOR (i,0,a.size())
    if (a[i] != '0'-1)
    {
        if (cando(pos,i))
        {
            ans += a[i];
            a[i] = '0'-1;
            backntr(pos+1);
            break;
        }
    }
}

int main()
{
    cin >> a >> b;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    if (b.size() > a.size())
    {
        cout << a;
        return 0;
    }
    backntr(0);
    cout << ans;
}