//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 200000;

pair<int, int> a[1 + MAXN], b[1 + MAXN];

bool CompareFirst(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
}

bool CompareSecond(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    int n, answer = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i].first >> b[i].second;
    sort(a + 1, a + n + 1, CompareFirst);
    sort(b + 1, b + m + 1, CompareSecond);
    answer = max(answer, a[n].first - b[1].second);
    sort(a + 1, a + n + 1, CompareSecond);
    sort(b + 1, b + m + 1, CompareFirst);
    answer = max(answer, b[m].first - a[1].second);
    cout << answer << "\n";
    return 0;
}