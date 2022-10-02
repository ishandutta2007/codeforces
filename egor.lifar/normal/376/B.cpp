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

long long a[1000000];

int main() {
    long long n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int c, d, e;
        cin >> c >> d >> e;
        a[c - 1] -= e;
        a[d - 1] += e;
    }
    long long s = 0;;
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            s += abs(a[i]);
        }
    }
    cout << s << endl;
    return 0;
}