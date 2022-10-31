#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int n, j, a=0, b=0, last=-1;
    vector<int> v;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> j;
        if (j<0) b++;
        if (b==3) a++, b=1, v.push_back(i-1-last), last=i-1;
    }
    a++; v.push_back(n-1-last);
    cout << a << endl;
    for (int i=0; i<a; i++) cout << v[i] << ' ';
    return 0;
}