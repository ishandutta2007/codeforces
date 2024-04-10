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
int a[250000];
multiset<int> s;


int gcd(int a, int b) {
    if (a == 0) { 
        return b;
    }
    return gcd(b % a, a);
}


int main() {   
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
   // cout << gcd(3, 2) << endl;
   // cout << (int)s.size() << endl;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int c = *(s.rbegin());
        s.erase(s.find(c));
        //cout << c << endl;
        v.push_back(c);
        //cout << "opa" <<
        //cout << c << ' '  << i + 1 << endl;
        for (int j = (int)v.size() - 2; j >= 0; j--) {
           // cout << gcd(c, v[j]) << ' ' << i + 1 << endl;
            s.erase(s.find(gcd(c, v[j])));
            s.erase(s.find(gcd(c, v[j])));
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}