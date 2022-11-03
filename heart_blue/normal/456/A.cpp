#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))

const LL INF = 1e7 + 7;
const int N = 1e2 + 10;
class Laptop
{
public:
    int price;
    int quality;
    Laptop(int _p, int _q): price(_p), quality(_q){}

    Laptop() : price(0), quality(0){}
    bool operator < (Laptop &l)
    {
        return price < l.price;
    }
};
vector<Laptop> vl;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p, q;
        cin >> p >> q;
        vl.push_back(Laptop(p, q));

    }
    sort(vl.begin(), vl.end());
    int maxv = -1;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (vl[i].quality < maxv) flag = 1;
        maxv = max(maxv, vl[i].quality);
    }
    if (flag) cout << "Happy Alex" << endl;
    else cout << "Poor Alex" << endl;
    return 0;
}