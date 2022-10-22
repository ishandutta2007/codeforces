#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int maxn = 405;

int inQueue[maxn * 2];
int A[maxn * 2];
int source, destination;
vector<int> E[maxn * 2];
int F[maxn * 2][maxn * 2];
int C[maxn * 2][maxn * 2];
int N;

double Cost[maxn * 2][maxn * 2], D[maxn * 2];

const double eps = 1e-6;
int cmp(double x, double y) {
    if (x + eps < y)
        return -1;
    if (y + eps < x)
        return 1;
    return 0;
}

bool BF() {
    for (int i = 0; i < 2 * maxn; ++i)
        D[i] = 0;
    memset(A, -1, sizeof(A));
    memset(inQueue, 0, sizeof(inQueue));

    queue<int> Q;
    A[source] = source;
    D[source] = 0;
    inQueue[source] = 1;
    Q.push(source);

    
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        if (x == destination)
            continue;
        inQueue[x] = 0;
        for (auto &y: E[x]) {
            if (F[x][y] < C[x][y] && (A[y] == -1 || cmp(D[x] + Cost[x][y], D[y]) == -1)) {
                D[y] = D[x] + Cost[x][y];
                A[y] = x;
                if (!inQueue[y]) {
                    Q.push(y);
                    inQueue[y] = 1;
                }
            }
        }
    }
    if (A[destination] == -1)
        return false;
    return true;
}

int main() {
    cin >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i)
        cin >> X[i] >> Y[i];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (Y[i] > Y[j]) {
                double dist = sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
                E[i].push_back(N + j);
                E[N + j].push_back(i);
                C[i][N + j] = 1;
                Cost[i][N + j] = dist;
                Cost[N + j][i] = -dist;
            }

    source = 2 * N;
    destination = 2 * N + 1;
    for (int i = 0; i < N; ++i) {
        E[source].push_back(i);
        E[i].push_back(source);
        C[source][i] = 2;
        
        E[i + N].push_back(destination);
        E[destination].push_back(i);
        C[i + N][destination] = 1;
    }

    // now max flow, min cost, luckily it grows by one
    int flow;
    double cost = 0;
    for (flow = 0; BF(); ++flow) {
        cost += D[destination];
        for (int i = destination; i != source; i = A[i]) {
            F[A[i]][i]++;
            F[i][A[i]]--;
        }
    }
    
    if (flow != N - 1) {
        cout << "-1\n";
        return 0;
    }

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cout << cost << "\n";
}