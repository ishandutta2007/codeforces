#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>


using namespace std;


int n;
int a[100001], p[100001];


int main() {
    cin >> n;
    set<int> s;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &p[i]);
        s.insert(p[i]);
        sum += (*s.begin()) * a[i];
    }
    cout << sum << endl;
    return 0;    
}