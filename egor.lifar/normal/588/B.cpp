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


long long n;
vector<long long> v;


int main() {
    cin >> n;
    long long a = 2;
    long long s = 1;
    while (a * a <= n) {
        if (n % a == 0) {
            s *= a;
            while (n % a == 0) {
                n /= a;
            }
        }
        a++;
    }
    s *= n;
    cout << s << endl;
    return 0;    
}