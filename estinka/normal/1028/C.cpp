#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
typedef long long ll;
using namespace std;

class rectangle
{
public:
    int x1, y1, x2, y2;
};
void overlap(rectangle& a, rectangle b)
{
    a.x1 = max(a.x1, b.x1);
    a.y1 = max(a.y1, b.y1);
    a.x2 = min(a.x2, b.x2);
    a.y2 = min(a.y2, b.y2);
}
bool good(rectangle& a)
{
    if (a.x1 <= a.x2 && a.y1 <= a.y2) return true;
    return false;
}
int n;
int find_common_rectangle(vector<rectangle>& v) 
{
    int o = 1, bad = -1;
    rectangle r = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        rectangle tmp = r;
        overlap(tmp, v[i]);
        if (!good(tmp))
        {
            if (bad == -1) bad = i;
            else return bad;
        }
        else
        {
            o++;
            r = tmp;
        }
    }
    if (o >= n - 1)
    {
        cout << r.x1 << " " << r.y1 << "\n";
        exit(0);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<rectangle> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
    int x = find_common_rectangle(v);
    swap(v[0], v[x]);
    find_common_rectangle(v);
    cout << "couldn't find the answer\n";
    return 0;
}