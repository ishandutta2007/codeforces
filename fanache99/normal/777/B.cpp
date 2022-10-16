//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 1000;
const int SIGMA = 10;

char a[1 + MAXN], b[1 + MAXN];
int first[SIGMA], second[SIGMA];

int Small(int n) {
    int answer = 0, sum = 0;
    for (int i = 0; i < SIGMA; i++) {
        sum += first[i];
        int add = min(sum, second[i]);
        sum -= add;
        first[i] = second[i] = 0;
        answer += add;
    }
    return n - answer;
}

int Big(int n) {
    int answer = 0, sum = 0;
    for (int i = 0; i < SIGMA; i++) {
        int add = min(sum, second[i]);
        sum -= add;
        answer += add;
        sum += first[i];
    }
    return answer;
}

int main() {
    int n;
    cin >> n >> a + 1 >> b + 1;
    for (int i = 1; i <= n; i++) {
        first[a[i] - '0']++;
        second[b[i] - '0']++;
    }
    cout << Small(n) << "\n";
    for (int i = 1; i <= n; i++) {
        first[a[i] - '0']++;
        second[b[i] - '0']++;
    }
    cout << Big(n) << "\n";
    return 0;
}