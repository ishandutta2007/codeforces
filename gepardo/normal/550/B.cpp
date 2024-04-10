#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, r, x;
int cnt;
int t[20], used[20];

void check()
{
    vector <int> v;
    int sum = 0;
    for (int i = 0; i < n; i++) if (used[i]) v.push_back(t[i]), sum += t[i];
    if (v.size() < 2) return;
    sort(v.begin(), v.end());
    int dif = v[v.size() - 1] - v[0];
    if (dif < x) return;
    if (sum < l || sum > r) return;
    cnt++;
}

void pereb(int step)
{
    if (step == n) { check(); return; }
    used[step] = true, pereb(step + 1);
    used[step] = false, pereb(step + 1);
}

main()
{
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++) cin >> t[i];
    pereb(0);
    cout << cnt;
}