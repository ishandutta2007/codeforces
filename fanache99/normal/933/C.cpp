#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <queue>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <set>
using namespace std;

const int MAXN = 200;
const double EPS = 1e-6;

int x[MAXN], y[MAXN], r[MAXN];
bool duplicate[MAXN], seen[MAXN];

int Compare(const double &a, const double &b) {
    if (a + EPS < b)
        return -1;
    if (b + EPS < a)
        return 1;
    return 0;
}

struct PairCompare {
    bool operator() (const pair<double, double> &a, const pair<double, double> &b) {
        if (Compare(a.first, b.first) == -1)
            return true;
        if (Compare(a.first, b.first) == 0)
            return Compare(a.second, b.second) == -1;
        return false;
    }
};

set< pair< double, double >, PairCompare > points[MAXN], current;
vector< int > edge[MAXN];

int DFS(int node) {
    int answer = points[node].size();
    seen[node] = true;
    for (auto &point : points[node])
        current.emplace(point);
    for (auto &neighbour : edge[node])
        if (!seen[neighbour])
            answer += DFS(neighbour);
    return answer;
}

int main() {
    //ifstream cin("tema.in");
    //ofstream cout("tema.out");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i];

    for (int i = 0; i < n; i++) {
        bool copied = false;
        for (int j = 0; j < i; j++)
            if (x[i] == x[j] && y[i] == y[j] && r[i] == r[j]) {
                copied = true;
                break;
            }
        if (copied) {
            duplicate[i] = true;
            continue;
        }
        for (int j = 0; j < i; j++)
            if (!duplicate[j]) {
                if ((x[i] - x[j]) * (x[i] -x[j]) + (y[i] - y[j]) * (y[i] - y[j]) == 0)
                    continue;
                double a = 2 * x[i] - 2 * x[j];
                double b = 2 * y[i] - 2 * y[j];
                double c = x[j] * x[j] - x[i] * x[i] + y[j] * y[j] - y[i] * y[i] + r[i] * r[i] - r[j] * r[j];
                double scale = max(abs(a), abs(b));
                a /= scale;
                b /= scale;
                c /= scale;
                if (Compare(a, 0)) {
                    double A = b * b + a * a;
                    double B = 2 * b * c + 2 * x[i] * a * b - 2 * y[i] * a * a;
                    double C = c * c + 2 * a * c * x[i] + x[i] * x[i] * a * a + y[i] * y[i] * a * a - r[i] * r[i] * a * a;
                    double Delta = B * B - 4 * A * C;
                    if (Compare(Delta, 0) == -1)
                        continue;
                    if (Compare(Delta, 0) == 0)
                        Delta = 0;
                    else
                        Delta = sqrt(Delta);
                    double y1 = (-B - Delta) / (2 * A);
                    double y2 = (-B + Delta) / (2 * A);
                    double x1 = (-c - b * y1) / a;
                    double x2 = (-c - b * y2) / a;
                    points[i].emplace(x1, y1);
                    points[j].emplace(x1, y1);
                    points[i].emplace(x2, y2);
                    points[j].emplace(x2, y2);
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
                else {
                    double A = b * b + a * a;
                    double B = 2 * a * c + 2 * y[i] * a * b - 2 * x[i] * b * b;
                    double C = c * c + 2 * b * c * y[i] + y[i] * y[i] * b * b + x[i] * x[i] * b * b - r[i] * r[i] * b * b;
                    double Delta = B * B - 4 * A * C;
                    if (Compare(Delta, 0) == -1)
                        continue;
                    if (Compare(Delta, 0) == 0)
                        Delta = 0;
                    else
                        Delta = sqrt(Delta);
                    double x1 = (-B - Delta) / (2 * A);
                    double x2 = (-B + Delta) / (2 * A);
                    double y1 = (-c - a * y1) / b;
                    double y2 = (-c - a * y2) / b;
                    points[i].emplace(x1, y1);
                    points[j].emplace(x1, y1);
                    points[i].emplace(x2, y2);
                    points[j].emplace(x2, y2);
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
        if (!seen[i] && !duplicate[i]) {
            current.clear();
            answer += DFS(i);
            answer -= current.size();
            answer++;
        }
    cout << answer + 1;
    return 0;
}