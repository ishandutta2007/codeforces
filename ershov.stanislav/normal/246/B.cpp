#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n, a, sum = 0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a;
        sum +=a;
    }
    if (sum%n == 0) cout << n;
    else cout << n-1;
    return 0;
}