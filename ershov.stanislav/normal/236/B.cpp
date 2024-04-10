#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#include <deque>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, ans=0, d[1111111];
    cin >> a >> b >> c;
    for (int i=1; i<=a*b*c; i++) for(int j=i; j<=a*b*c; j+=i) d[j]++;
    for(int i=1; i<=a; i++) for (int j=1; j<=b; j++) for (int k=1; k<=c; k++) ans+=d[i*j*k];
    cout << ans;
    return 0;
}