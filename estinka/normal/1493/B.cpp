#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <array>
#include <list>
typedef long long ll;
using namespace std;

map<int, int> r;
int transform(int num)
{
    num = (num % 10) * 10 + (num / 10);
    if (r.count(num / 10)) 
        num = num - (num / 10) * 10 + r[num / 10] * 10;
    else return -1;
    if (r.count(num % 10)) num = num - (num % 10) + r[num % 10];
    else return -1;
    return num;
}
bool good(int myh, int mym, int h, int m)
{
    swap(myh, mym);
    myh = transform(myh), mym = transform(mym);
    if (myh < 0 || myh >= h || mym < 0 || mym >= m) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    r[0] = 0;
    r[1] = 1;
    r[2] = 5;
    r[5] = 2;
    r[8] = 8;
    int t;
    cin >> t;
    while (t--)
    {
        int h, m, myh, mym; char c;
        cin >> h >> m;
        cin >> myh >> c >> mym;
        while (!good(myh, mym, h, m))
        {
            mym++;
            if (mym >= m) mym = 0, myh++;
            if (myh >= h) myh = mym = 0;
        }
        string s1 = to_string(myh + 100), s2 = to_string(mym + 100);
        s1.erase(s1.begin());
        s2.erase(s2.begin());
        //cout << "                   ";
        cout << s1 << ":" << s2 << "\n";
    }
    return 0;
}