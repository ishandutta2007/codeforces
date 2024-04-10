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
    int a1,a2,a3;
    int b1,b2,b3;
    int n;
    cin >> a1>>a2>>a3>>b1>>b2>>b3>>n;
    a1+=a2+a3;
    b1+=b2+b3;
    a1 = (a1 + 4) / 5;
    b1= (b1 + 9) / 10;
    if (a1 +b1<=n)cout << "YES"; else cout << "NO";
    return 0;
}