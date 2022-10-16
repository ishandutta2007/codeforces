//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 7000;

int x[2][1 + MAXN];
int answer[2][1 + MAXN], seen[2][1 + MAXN];
queue<pair<int, int> > Queue;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= 1; i++) {
        cin >> x[i][0];
        for (int j = 1; j <= x[i][0]; j++)
            cin >> x[i][j];
    }
    Queue.push(make_pair(0, 1));
    Queue.push(make_pair(1, 1));
    answer[0][1] = answer[1][1] = -1;
    while (!Queue.empty()) {
        int which = Queue.front().first, other = 1 - which, where = Queue.front().second;
        Queue.pop();
        for (int i = 1; i <= x[other][0]; i++) {
            int before = where - x[other][i];
            if (before < 1)
                before += n;
            seen[other][before]++;
            if (!answer[other][before]) {
                if (answer[which][where] == -1) {
                    answer[other][before] = 1;
                    Queue.push(make_pair(other, before));
                    continue;
                }
                if (seen[other][before] == x[other][0]) {
                    answer[other][before] = -1;
                    Queue.push(make_pair(other, before));
                }
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 2; j <= n; j++) {
            if (answer[i][j] == -1)
                cout << "Lose ";
            if (!answer[i][j])
                cout << "Loop ";
            if (answer[i][j] == 1)
                cout << "Win ";
        }
        cout << "\n";
    }
    return 0;
}