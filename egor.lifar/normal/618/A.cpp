#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int n;


int main() {
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(1);
        while ((int)v.size() >= 2) {
            if (v.back() == (int)v[(int)v.size() - 2]) {
                v.pop_back();
                v.back()++;
                continue;
            }
            break;
        }
    }
    for (int i = 0; i < (int)v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}