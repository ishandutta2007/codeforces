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
#include <bitset>
#include <unordered_map>


using namespace std;



int n;


int main() {    
    cin >> n;
    long long t = 2;
    for (int i = 2; i <= n + 1; i++) {
        if (i == 2) {
            printf("%lld\n", 2LL);
        } else {
            printf("%lld\n", 1LL * i * i * (i - 1) - (i - 2));
            t = 1LL * i * (i - 1);
        }
    }
    return 0;
}