#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>

using namespace std;

const int SIGMA = 3;

int has[SIGMA];

int main() {
    //ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        string s;
        cin >> s;
        int n = s.size();
        for (int i = 0; i < SIGMA; i++)
            has[i] = 0;
        int answer = n + 1;
        for (int i = 0, j = 0; i < n; i++) {
            has[s[i] - '1']++;
            while (has[s[j] - '1'] > 1) {
                has[s[j] - '1']--;
                j++;
            }
            if (has[0] && has[1] && has[2])
                answer = min(answer, i - j + 1);
        }
        if (answer == n + 1)
            answer = 0;
        cout << answer << "\n";
    }
    return 0;
}