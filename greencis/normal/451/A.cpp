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

int main()
{
    int n,m;
    cin>>n>>m;
    m = min(n,m);
    if (m % 2) cout << "Akshat"; else cout << "Malvika";
    return 0;
}