#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>


using namespace std;
   

int n;
int p[101];


int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    scanf("\n");
    bool b = 1;
    for (int i = 0; i < n; i++) {
        char c[104];
        cin.getline(c, 102);
        int cnt = 0;
        for (int j = 0; j < strlen(c); j++) {
            if (c[j] == 'a' || c[j] == 'u' || c[j] == 'e' || c[j] == 'o' || c[j] == 'i' || c[j] == 'y') {
                cnt++;
            }
        }
        if (cnt != p[i]) {
            b = 0;
        }
        scanf("\n");
    }
    if (b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}