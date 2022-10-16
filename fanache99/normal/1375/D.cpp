#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1000;

int v[1 + MAXN];

int mex(int n, int a[]) {
    vector<int> seen(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        seen[a[i]] = 1;
    }
    int answer = 0;
    while (seen[answer]) {
        answer++;
    }
    return answer;
}

bool good(int n, int a[]) {
    for (int i = 1; i <= n; i++) {
        if (a[i] != i - 1) {
            return false;
        }
    }
    return true;
}

int main(){
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        vector<int> answer;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        while (!good(n, v)) {
            int x = mex(n, v);
            if (x == n) {
                for (int i = 1; i <= n; i++) {
                    if (v[i] != i - 1) {
                        answer.emplace_back(i);
                        v[i] = n;
                        break;
                    }
                }
            } else {
                answer.emplace_back(x + 1);
                v[x + 1] = x;
            }
        }
        cout << answer.size() << "\n";
        for (auto it : answer) {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}