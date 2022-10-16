//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const int MAXF = 10000;

struct Station {
    int x, r;
    int xn, an, bn;
    int f;
};

Station v[1 + MAXN];

bool CompareX(const Station &a, const Station &b) {
    return a.x < b.x;
};

bool CompareLeft(const Station &a, const Station &b) {
    return a.x - a.r < b.x - b.r;
};

int xn[1 + MAXN];
vector<Station> first[1 + MAXF], second[1 + MAXF];
int fenwick[1 + MAXN];

void Update(int x, int n, int add) {
    for (x; x <= n; x += (x & -x))
        fenwick[x] += add;
}

int Query(int x) {
    int answer = 0;
    for (x; x > 0; x -= (x & -x))
        answer += fenwick[x];
    return answer;
}

long long Count(int which, int n) {
    priority_queue<pair<int, int> > Heap;
    sort(first[which].begin(), first[which].end(), CompareX);
    sort(second[which].begin(), second[which].end(), CompareLeft);
    long long answer = 0;
    for (int i = 0, j = 0; i < first[which].size(); i++) {
        while (j < second[which].size() && first[which][i].x >= second[which][j].x - second[which][j].r) {
            Update(second[which][j].xn, n, 1);
            Heap.push(make_pair(-(second[which][j].x + second[which][j].r), second[which][j].xn));
            j++;
        }
        while (!Heap.empty() && -Heap.top().first < first[which][i].x) {
            Update(Heap.top().second, n, -1);
            Heap.pop();
        }
        answer = answer + Query(first[which][i].bn) - Query(first[which][i].an);
    }
    while (!Heap.empty()) {
        Update(Heap.top().second, n, -1);
        Heap.pop();
    }
    answer -= first[which].size();
    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> v[i].x >> v[i].r >> v[i].f;
    sort(v + 1, v + n + 1, CompareX);
    for (int i = 1; i <= n; i++) {
        v[i].xn = i;
        xn[i] = v[i].x;
    }
    for (int i = 1; i <= n; i++) {
        int left = 1, right = n;
        v[i].an = 0;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (xn[middle] < v[i].x - v[i].r) {
                v[i].an = middle;
                left = middle + 1;
            }
            else
                right = middle - 1;
        }
        left = 1;
        right = n;
        v[i].bn = 0;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (xn[middle] <= v[i].x + v[i].r) {
                v[i].bn = middle;
                left = middle + 1;
            }
            else
                right = middle - 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        first[v[i].f].push_back(v[i]);
        for (int j = max(v[i].f - k, 1); j <= min(v[i].f + k, MAXF); j++)
            second[j].push_back(v[i]);
    }
    long long answer = 0;
    for (int i = 1; i <= MAXF; i++)
        if (first[i].size() && second[i].size())
            answer += Count(i, n);
    cout << answer / 2 << "\n";
    return 0;
}