#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int n,d,t[1000005];

int main()
{
    int q=0,qq=0;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
            cin >> t[i];
            q+=t[i] + 10;
            qq+=2;
    }
    q-=10;
    qq-=2;
    if (q > d) cout << -1;
    else {
        qq += (d - q) / 5;
        cout<<qq;
    }
}