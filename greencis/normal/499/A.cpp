#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

int n,x,a,b,ans,cur=1;

int main()
{
    cin >> n >> x;
    while (n--) {
        cin >> a >> b;
        while (cur + x <= a) cur += x;
        ans += b - cur + 1;
        cur = b+1;
    }
    cout << ans;
    return 0;
}