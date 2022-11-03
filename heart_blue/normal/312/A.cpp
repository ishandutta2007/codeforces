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
const int N = 1e3 + 10;

int main()
{
    //freopen("input.txt","r",stdin);
    string str;
    int n;
    string miao = "miao.";
    string lala = "lala.";
    cin >> n;
    getchar();
    while (n--)
    {
        getline(cin, str);
        int flag1, flag2;
        flag1 = flag2 = 0;
        if (miao == str.substr(0, 5)) flag1 = 1;
        if (lala == str.substr(max((int)str.length() - 5,0))) flag2 = 1;
        if (!(flag1^flag2))
        {
            cout << "OMG>.< I don't know!" << endl;
        }
        else if (flag1)
        {
            cout << "Rainbow's" << endl;
        }
        else
        {
            cout << "Freda's" << endl;
        }
    }
    return 0;
}