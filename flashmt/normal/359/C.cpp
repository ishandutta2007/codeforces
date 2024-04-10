#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int BASE = int(1e9) + 7;

long long power(long long x, long long y)
{
    if (!y) return 1;
    long long res = power(x, y / 2);
    res = res * res % BASE;
    if (y % 2) res = res * x % BASE;
    return res;
}

int main()
{
    //freopen("c.in", "r", stdin);
    int n, x, a[100100];
    long long sum = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    
    if (a[n - 1] == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    
    long long nume = sum - a[n - 1];
    
    map <int,int> cnt;
    for (int i = 0; i < n; i++) cnt[a[n - 1] - a[i]]++;
    
    for (map <int,int>::iterator it = cnt.begin(); it != cnt.end(); it++) 
        if (it -> second % x == 0 && it -> second)
            cnt[it -> first + 1] += it -> second / x;
        else
        {
            nume += it -> first;
            break;
        }
    
    cout << power(x, min(sum, nume)) << endl;
}