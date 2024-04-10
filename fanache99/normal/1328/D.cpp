#include <iostream>
#include <string>

using namespace std;

const int MAXN = 200000;

int v[1 + MAXN];
int answer[1 + MAXN];

bool Try2(int n) {
    answer[1] = 1;
    for (int i = 2; i <= n; i++) {
        answer[i] = 1;
        if (answer[i] == answer[i - 1] && v[i] != v[i - 1])
            answer[i]++;
    }
    if (answer[n] == answer[1] && v[n] != v[1]) {
        bool found = false;
        for (int i = 2; i <= n; i++)
            if (v[i] == v[i - 1]) {
                found = true;
                for (int j = i; j <= n; j++)
                    answer[j] = 3 - answer[j];
                break;
            }
        if (!found)
            return false;
    }
    cout << 2 << "\n";
    for (int i = 1; i <= n; i++)
        cout << answer[i] << " ";
    cout << "\n";
    return true;
}

void Do3(int n) {
    cout << "3\n";
    answer[1] = 1;
    for (int i = 2; i < n; i++) {
        answer[i] = 1;
        if (answer[i] == answer[i - 1] && v[i] != v[i - 1])
            answer[i]++;
    }
    answer[n] = 1;
    if (answer[n] == answer[n - 1] && v[n] != v[n - 1])
        answer[n]++;
    if (answer[n] == answer[1] && v[n] != v[1])
        answer[n]++;
    if (answer[n] == answer[n - 1] && v[n] != v[n - 1])
        answer[n]++;
    if (answer[n] == answer[1] && v[n] != v[1])
        answer[n]++;
    for (int i = 1; i <= n; i++)
        cout << answer[i] << " ";
    cout << "\n";
}

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        bool atLeast2 = false;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            if (v[i] != v[1])
                atLeast2 = true;
        }
        if (!atLeast2) {
            cout << "1\n";
            for (int i = 1; i <= n; i++)
                cout << "1 ";
            cout << "\n";
        }
        else
            if (!Try2(n))
                Do3(n);
    }
    return 0;
}