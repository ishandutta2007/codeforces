#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const long long INF = 10000000000LL;

queue <long long> myQueue;
vector <long long> lucky;

long long l, r;

int main () {
    cin >> l >> r;
    myQueue.push(4);
    myQueue.push(7);
    while (!myQueue.empty()) {
        long long cur = myQueue.front();
        myQueue.pop();
        lucky.push_back(cur);
        if (cur * 10 + 4 <= INF) {
            myQueue.push(cur * 10 + 4);
        }
        if (cur * 10 + 7 <= INF) {
            myQueue.push(cur * 10 + 7);
        }
    }
    sort(lucky.begin(), lucky.end());
    long long result = 0, begin = l;
    for (vector <long long> :: iterator iter = lucky.begin();
            iter != lucky.end(); ++ iter) {
        if (begin > r) {
            break;
        }
        if (begin <= *iter) {
            long long end = min(*iter, r);
            result += (end - begin + 1) * (*iter);
            begin = end + 1;
        }
    }
    cout << result << endl;
    return 0;
}