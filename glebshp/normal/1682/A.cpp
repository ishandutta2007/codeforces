#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    cin >> tnum;
    for (int tc = 0; tc < tnum; tc++) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        int lb = n / 2;
        int rb = n / 2;
        if (n % 2 == 0) {
            lb = n / 2 - 1;
        }
        while (lb >= 0 && rb < n) {
            if (str[lb] == str[n / 2]) {
                lb--, rb++;
            } else {
                break;
            }
        }

        cout << (rb - lb - 1) << endl;
    }

    return 0;
}