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
const LL INF = 1e9 + 1;
const int N = 3e3;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    string s1, s2, s3;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '@')
        {
            s1 = str.substr(0, i);
            s2 = str.substr(i + 1);
            break;
        }
    }
    for (int i = 0; i < s2.length(); i++)
    {
        if (s2[i] == '/')
        {
            s3 = s2.substr(i+1);
            s2 = s2.substr(0, i);
            if (s3.length() == 0)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (s1.length() > 16 || s1.length() == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (auto &c : s1)
    {
        if (!isalpha(c) && !isdigit(c) && c != '_')
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (s2.length() > 32 || s2.length() == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (auto &c : s2)
    {
        if (!isalpha(c) && !isdigit(c) && c != '_' && c != '.')
        {
            cout << "NO" << endl;
            return 0;
        }
        if (s2.front() == '.' || s2.back() == '.')
        {
            cout << "NO" << endl;
            return 0;
        }
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] == '.' && str[i] == str[i - 1])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (s3.length() > 16)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (auto &c : s3)
    {
        if (!isalpha(c) && !isdigit(c) && c != '_')
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}