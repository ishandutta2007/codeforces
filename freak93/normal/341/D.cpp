#include <iostream>

using namespace std;

int N;
long long A[2][2][1005][1005];

long long query(int x, int y) {
    long long answer = 0;
    for (int a = x; a; a -= (a & -a))
        for (int b = y; b; b -= (b & -b))
            answer ^= A[x % 2][y % 2][a][b];
    return answer;
}

void update(int x, int y, long long v) {
    for (int a = x; a <= N; a += (a & -a))
        for (int b = y; b <= N; b += (b & -b))
            A[x % 2][y % 2][a][b] ^= v;
}

void update(int x1, int y1, int x2, int y2, long long v) {
    update(x1, y1, v);
    update(x1, y2, v);
    update(x2, y1, v);
    update(x2, y2, v);
}

int main() {
    ios::sync_with_stdio(false);
    int M; cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int type, x1, y1, x2, y2;
        cin >> type >> x1 >> y1 >> x2 >> y2;
        if (type == 1) {
            --x1; --y1;
        } else {
            ++x2; ++y2;
        }

        if (type == 1) {
            cout << (query(x1, y1) ^ query(x1, y2) ^ query(x2, y2) ^ query(x2, y1)) << "\n";
        } else {
            long long v; cin >> v;
            update(x1, y1, x2, y2, v);
        }
    }
}