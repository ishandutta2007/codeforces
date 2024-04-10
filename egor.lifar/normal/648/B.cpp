#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>


using namespace std;


int n;
int a[2001];
vector<int> who[200001];


int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        sum += a[i];
        who[a[i]].push_back(i + 1);
    }
    sum /= n;
    for (int i = 1; i <= 100000; i++) {
        if (!who[i].empty()) {
            if (i * 2 == sum) {
                while ((int)who[i].size() >= 2) {
                    printf("%d %d\n", i, i);
                    who[i].pop_back();
                    who[i].pop_back();
                }
            }  else {
                 while (!who[i].empty() && !who[sum - i].empty()) {
                    printf("%d %d\n", i, sum - i);
                    who[i].pop_back();
                    who[sum - i].pop_back();
                }
            }
        }
    }
    return 0;
}