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

const int INF = 1e9 + 7;
const int N = 2e5 + 1;
vector<string> vs = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H" };

int check(string s)
{
    for (int i = 0; i < vs.size(); i++)
    {
        if (vs[i] == s) return i;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int a = check(s1);
    int b = check(s2);
    int c = check(s3);
    vector<int> v = { a, b, c };
    sort(v.begin(), v.end());
    do
    {
        a = v[0], b = v[1], c = v[2];
        if ((b - a == 4 || a - b == 8) && (c - b == 3 || b - c == 9))
        {
            cout << "major" << endl;
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));
    do
    {
        a = v[0], b = v[1], c = v[2];
        if ((b - a == 3 || a - b == 9) && (c - b == 4 || b - c == 8))
        {
            cout << "minor" << endl;
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << "strange" << endl;

    return 0;
}