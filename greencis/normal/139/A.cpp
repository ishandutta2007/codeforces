#include <iostream>
using namespace std;

int n,a[1005],cur=0;

int main()
{
    cin >> n;
    for (int i = 0; i < 7; ++i)cin>>a[i];
    while (n > 0) {
        n -= a[cur];
        if (n <= 0) { cout << cur+1; return 0; }
        cur = (cur+1)%7;
    }
    return 0;
}