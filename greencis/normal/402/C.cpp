#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

int t,n,p;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> p;
        int cnt = 2*n + p;
        for (int i = 1; i <= n && cnt; ++i) {
            for (int j = i+1; j <= n && cnt; ++j) {
                cout << i << " " << j << endl;
                --cnt;
            }
        }
    }

    return 0;
}