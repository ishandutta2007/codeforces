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

const int INF = 1e6 + 3;
const int N = 1e3 + 1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    map<string, int> m1;
    m1["rat"] = 0;
    m1["woman"] = 1;
    m1["child"] = 1;
    m1["man"] = 2;
    m1["captain"] = 3;
    int n;
    cin >> n;
    vector<pair<pair<int, int>, string>> vs;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vs.push_back({ { m1[s2], i }, s1 });
    }
    sort(vs.begin(), vs.end());
    for (auto it : vs) cout << it.second << endl;
    
    return 0;
}