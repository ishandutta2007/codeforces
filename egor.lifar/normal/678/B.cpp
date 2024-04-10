#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>



using namespace std;


int y;


bool visokosniy(int x) {
    if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)) {
        return 1;
    }
    return 0;
}


int main() {
    cin >> y;
    bool b = visokosniy(y);
    int t = (visokosniy(y) ? 366 % 7: 365 % 7);
    while (true) {
        y++;
        if (t == 0 && b == visokosniy(y)) {
            cout << y << endl;
            return 0;
        }
        t += (visokosniy(y) ? 366 % 7: 365 % 7);;
        t %= 7;
    }
    return 0;   
}