#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n<3) cout << -1;
    else {
        cout << "2 3 ";
        for (int i=2; i<n; i++) cout << "1 ";
    }
    return 0;
}