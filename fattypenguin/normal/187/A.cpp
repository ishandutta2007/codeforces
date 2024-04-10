#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    map<int, int> M;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int x, i = 0; i < n; ++i)
    {
        cin >> x;
        M[x] = i;
    }
    for (int i = 0; i < n; ++i) a[i] = M[a[i]];
    int ans = 1;
    for (int i = 1; i < n; ++i) if (a[i] > a[i-1]) ++ans; else break;
    printf("%d\n", n-ans);
    return 0;
}