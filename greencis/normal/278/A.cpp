#include <iostream>

using namespace std;

int n,a[105],x,y;

int main()
{
    cin>>n;
    for (int i = 1; i<=n;++i) {
        cin>>a[i];
        a[i] += a[i - 1];
    }
    cin >> x >> y;
    if (x > y) swap(x,y);
    int q = a[y-1] - a[x-1];
    cout << min(q,a[n]-q);
    return 0;
}