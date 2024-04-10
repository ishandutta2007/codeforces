#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
long long a, b;
int k;
long long pd[1000000];

long long dist(int a, int b) {
    pd[b] = 0;
    
    for (int i = b+1; i <= a; i++) {
        pd[i] = pd[i-1]+1;
        for (int x = 2; x <= k; x++) {
            if ((i - (i % x)) >= b) pd[i] = min(pd[i], pd[i - (i%x)] + 1);
        }
    }
    
    return pd[a];
}

const int magic = 360360;

int main() {
    cin >> b >> a >> k;
    
    int m1 = a%magic;
    int m2 = b%magic;
    if (b/magic == a/magic) {
        cout << dist(m2, m1) << endl;
        
        return 0;
    }
    else {
        long long d1 = dist(m2,0);
        long long d2 = dist(magic,0);
        long long d3 = dist(magic,m1);
        
        cout << d1 + d2 * (b/magic - a/magic - 1) + d3 << endl;
        return 0;
    }   
}