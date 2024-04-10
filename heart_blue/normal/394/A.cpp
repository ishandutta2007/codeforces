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
const int N = 1e3 + 10;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    int sum = 0;
    int i;
    int a, b, c;
    a = b = c = 0;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '|') a++;
        else break;
    }
    for (i = i+1; i < str.length(); i++)
    {
        if (str[i] == '|') b++;
        else break;
    }
    for (i = i + 1; i < str.length(); i++)
    {
        if (str[i] == '|') c++;
        else break;
    }
    if (a + b == c)
    {
        cout << str << endl;
        return 0;
    }
    if (a + b - c == 2)
    {
        if (a > 1 || b > 1)
        {

            if (a > 1)
            {
                a--;
                c++;
            }
            else if (b > 1)
            {
                b--;
                c++;
            }
            for (int i = 0; i < a; i++) cout << '|';
            cout << '+';
            for (int i = 0; i < b; i++) cout << '|';
            cout << '=';
            for (int i = 0; i < c; i++) cout << '|';
            return 0;
        }
    }
    if (a + b - c == -2)
    {
        a++;
        c--;
        for (int i = 0; i < a; i++) cout << '|';
        cout << '+';
        for (int i = 0; i < b; i++) cout << '|';
        cout << '=';
        for (int i = 0; i < c; i++) cout << '|';
        return 0;
    }
    cout << "Impossible" << endl;
    return 0;
}