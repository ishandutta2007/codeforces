#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>


using namespace std;


int n;
int a[100001];

    
int main() {
    cin >> n;
    int ans = 1;
    int l = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i == 0 || a[i] > a[i - 1]) {
            l++;
        } else {
            l = 1;
        }
        ans = max(ans, l);
    }
    cout << ans << endl;
    return 0;
}