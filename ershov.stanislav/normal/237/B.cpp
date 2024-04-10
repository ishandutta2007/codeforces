#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct change { int x; int y; int p; int q; };

int main()
{
    int n, *c, *l, *j, num = 0, now_i=1, now_j=1, **numbers;
    vector<change> changes;
    cin >> n;
    c = new int[n];
    for (int i=0; i<n; i++) {
        cin >> c[i];
        num += c[i];
    }
    l = new int[num+1];
    j = new int[num+1];
    numbers = new int*[n];
    for (int i=0; i<n; i++) {
        numbers[i] = new int[c[i]];
        for (int k=0; k<c[i]; k++) {
            int a;
            cin >> a;
            l[a] = i;
            j[a] = k;
            numbers[i][k] = a;
        }
    }
    for (int i=1; i<=num; i++) {
        if (c[now_i-1] < now_j) {
            now_i++;
            now_j=1;
        }
        if (l[i] != now_i-1 || j[i] != now_j-1) {
            l[numbers[now_i-1][now_j-1]] = l[i];
            j[numbers[now_i-1][now_j-1]] = j[i];
            numbers[l[i]][j[i]] = numbers[now_i-1][now_j-1];
            change c;
            c.x = now_i;
            c.y = now_j;
            c.p = l[i]+1;
            c.q = j[i]+1;
            changes.push_back(c);
        }
        now_j++;
    }
    cout << changes.size() << endl;
    for (int i=0; i<changes.size(); i++) cout << changes[i].x << ' ' << changes[i].y << ' ' << changes[i].p << ' ' <<
        changes[i].q << endl;
    return 0;
}