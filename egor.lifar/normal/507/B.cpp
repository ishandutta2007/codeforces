#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


double r, x, y, x2, y2;


int main() {
    cin >> r >> x >> y >> x2 >> y2;
    cout << ceil(sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y)) / (r * 2.0)) << endl;
    return 0;
}