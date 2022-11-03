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
const int INF = 1e9 + 3;
const int N = 4e4 + 10;


bool check(string str)
{
    int cnt = 0;
    for (int i = 1; i < str.length(); i++)
    {
        if (isdigit(str[i]) && !isdigit(str[i - 1]))
        {
            cnt++;
        }
    }
    return cnt == 2;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    while (n--)
    {

        string str;
        cin >> str;

        if (check(str))
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (isalpha(str[i])) str[i] = ' ';
            }
            stringstream sin(str);
            int r, c;
            sin >> r >> c;
            str.clear();
            do
            {
                str.push_back((c-1) % 26 + 'A');
                c = (c-1)/26;
            } while (c);
            reverse(str.begin(), str.end());
            cout << str << r << endl;
            continue;
        }
        else
        {
            string s2;

            int c = 0;
            for (int i = 0; i < str.length(); i++)
            {
                
                if (isdigit(str[i]))
                {
                    s2 = str.substr(i);
                    break;
                }
                c *= 26;
                c += str[i] - 'A' + 1;
            }
            cout << 'R' << s2 << 'C' << c << endl;
            continue;
        }
    }

    return 0;
}