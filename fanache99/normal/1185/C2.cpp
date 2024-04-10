// Example program
#include <iostream>
#include <string>
#include <queue>

using namespace std;

priority_queue<int> small, large;
int sumSmall = 0;

void Balance(int limit) {
    while (!large.empty() && sumSmall - large.top() <= limit) {
        sumSmall -= large.top();
        small.push(-large.top());
        large.pop();
    }
    while (sumSmall > limit) {
        large.push(-small.top());
        sumSmall -= small.top();
        small.pop();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        Balance(m - t);
        cout << large.size() << " ";
        if (small.empty() || t > small.top())
            large.push(-t);
        else {
            small.push(t);
            sumSmall += t;
        }
    }
    return 0;
}