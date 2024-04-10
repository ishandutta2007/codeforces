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
#include <assert.h>


using namespace std;

 
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int d = max(a, max(b, c));
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= d; j++) {
            if (i * j == a) {
                if (j * (b / i) == c && b % i == 0) {
                    int k = b / i;
                    cout << 4 * i + 4 * j + 4 * k << endl;
                    return 0; 
                } else {
                    if (i * (b / j) == c && b % j == 0) {
                        int k = b / j;
                        cout << 4 * i + 4 * j + 4 * k << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}