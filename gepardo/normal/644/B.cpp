#include <iostream>
#include <queue>
#define int long long

using namespace std;

int n, b;
vector < pair<int,int> > proc;
int busy = -1;
vector <int> ans;
priority_queue < pair<int,int> > reqs;
queue <int> reqQueue;

void doNext()
{
    pair<int, int> p = reqs.top(); reqs.pop();
    p.second = -p.second;
    if (p.second < 0)
    {
        ans[busy] = -p.first;
        busy = -1;
        if (reqQueue.size() != 0)
        {
            int t = reqQueue.front(); reqQueue.pop();
            busy = t;
            reqs.push({p.first - proc[t].second, 1});
        }
    }
    else
    {
        if (busy < 0)
        {
            int t = p.second;
            busy = t;
            reqs.push({p.first - proc[t].second, 1});
        }
        else if (reqQueue.size() < b) reqQueue.push(p.second);
    }
}

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> b;
    proc.resize(n), ans.assign(n, -1);
    for (int i = 0; i < n; i++) cin >> proc[i].first >> proc[i].second;
    for (int i = 0; i < n; i++) reqs.push({-proc[i].first, -i});
    while (!reqs.empty()) doNext();
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}