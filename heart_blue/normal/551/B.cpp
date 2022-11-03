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
const LL INF = 1e9;
const int N = 2e5;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s1, s2, s3;
    int a[26] = { 0 };
    int b[26] = { 0 };
    int c[26] = { 0 };
    cin >> s1 >> s2 >> s3;
    for (auto &x : s1) a[x - 'a'] ++;
    for (auto &x : s2) b[x - 'a']++;
    for (auto &x : s3) c[x - 'a'] ++;
    int k = 0;
    for (int i = 0; i < 26; i++) if (a[i]>0) { k = i; break; }
    int sum = 0;
    int key = 0;
    for (int i = 0; i * b[k] <= a[k]; i++)
    {
        int flag = 0;
        for (int j = 0; j < 26; j++) if (a[j] < b[j] * i) flag = 1;
        if (flag) break;
        for (int j = 0; j < 26; j++) a[j] -= b[j] * i;
        int tmp = INF;
        for (int j = 0; j < 26; j++) if(c[j]) tmp = min(tmp, a[j] / c[j]);
        if (tmp == INF) tmp = -INF;
        if (tmp + i > sum)
        {
            sum = tmp + i;
            key = i;
        }
        for (int j = 0; j < 26; j++) a[j] += b[j] * i;
    }
    for (int i = 0; i < key; i++) cout << s2;
    for (int i = key; i < sum; i++) cout << s3;
    for (int i = 0; i < 26; i++) a[i] -= key*b[i] + (sum - key)*c[i];
    for (int i = 0; i < 26; i++) cout << string(a[i], char(i + 'a'));
    return 0;

}