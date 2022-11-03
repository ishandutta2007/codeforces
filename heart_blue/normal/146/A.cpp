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
const int N = 1e6 + 10;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    string str;
    cin >> n;
    cin >> str;
    int sum = 0;
    for (int i = 0; i < str.length(); i++) sum += str[i]-'0';
    int tmp = 0;
    for (int i = 0; i < str.length() / 2; i++) tmp += str[i]-'0';
    int flag = 1;
    for (int i = 0; i < str.length(); i++) if (str[i] != '4'&& str[i] != '7') flag = 0;
    if (tmp * 2 == sum && flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}