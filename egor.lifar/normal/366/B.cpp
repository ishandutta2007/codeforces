#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>



using namespace std;


int main(){
    int n, k, a[100000];
    cin >> n >> k;
    pair<int, int> p[100000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        p[i % k] = make_pair(p[i % k].first + a[i], i % k);
    }
    sort(p, p + k);
    cout << p[0].second + 1 << endl;
    return 0;
}