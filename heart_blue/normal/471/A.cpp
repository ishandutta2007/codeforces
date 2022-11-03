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
const int N = 1e5 + 10;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    
    map<int, int> m;
    for (int i = 0; i < 6; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    if (m.size() == 1)
    {
        cout << "Elephant" << endl;
        return 0;
    }
    if (m.size() == 2)
    {
        vector<int> v;
        for (auto it : m)
        {
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        if (v.back() == 5)
        {
            cout << "Bear" << endl;
            return 0;
        }
        if (v.back() == 4)
        {
            cout << "Elephant" << endl;
            return 0;
        }
        
    }
    if (m.size() == 3)
    {
        vector<int> v;
        for (auto it : m)
        {
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        if (v.back() == 4)
        {
            cout << "Bear" << endl;
            return 0;
        }
        
    }
    cout << "Alien" << endl;


    return 0;
}