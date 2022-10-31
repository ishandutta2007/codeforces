#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, m, h, t;
vector<vector<int> > graph;
int *f;

bool try_edge(int u, int v) {
    if (graph[u].size() < h+1 || graph[v].size() < t+1) return false;
    for (int i=0; i<graph[u].size(); i++) f[graph[u][i]] = 1;
    int a = graph[u].size()-1, b = graph[v].size()-1, c = 0, need, now = 0;
    for (int i=0; i<graph[v].size(); i++) {
        if (f[graph[v][i]]) {
            a--;
            b--;
            c++;
            f[graph[v][i]]++;
        }
    }
    if (a+b+c<h+t) {
        for (int i=0; i<graph[u].size(); i++) f[graph[u][i]] = 0;
        for (int i=0; i<graph[v].size(); i++) f[graph[v][i]] = 0;
        return false;
    }
    cout << "YES" << endl << u + 1 << ' ' << v + 1 << endl;
    need = t-b;
    for (int i=0; i<graph[u].size() && now<h; i++) {
        if (graph[u][i] == v) continue;
        now++;
        if (f[graph[u][i]] == 1) cout << graph[u][i] + 1 << ' ';
        else if (c>need) {
            cout << graph[u][i] + 1<< ' ';
            c--;
            f[graph[u][i]] = 3;
        }
        else now--;
    }
    now = 0;
    cout << endl;
    for (int i=0; i<graph[v].size() && now<t; i++) {
        if (graph[v][i] == u) continue;
        now++;
        if (f[graph[v][i]] != 3) cout << graph[v][i] + 1<< ' ';
        else now--;
    }
    for (int i=0; i<graph[u].size(); i++) f[graph[u][i]] = 0;
    for (int i=0; i<graph[v].size(); i++) f[graph[v][i]] = 0;
    return true;
    /*set<int> s1, s2, sc;
    for (vector<int>::iterator i=graph[u].begin(); i!=graph[u].end(); i++) s1.insert(*i);
    for (vector<int>::iterator i=graph[v].begin(); i!=graph[v].end(); i++)
    {
        if (s1.count(*i) == 0) s2.insert(*i);
        else { sc.insert(*i); s1.erase(*i); }
    }
    s1.erase(v);
    s2.erase(u);
    if (s1.size() + s2.size() + sc.size() >= h+t) {
        cout << "YES" << endl;
        cout << u + 1 << ' ' << v + 1<< endl;
        int i=0;
        set<int>::iterator j;
        for (j=s1.begin(); j!=s1.end() && i<h; j++) {
            cout << *j + 1 << ' ';
            i++;
        }
        for (j=sc.begin(); j!=sc.end() && i<h+t; j++) {
            if (i==h) cout << endl;
            cout << *j + 1 << ' ';
            i++;
        }
        for (j=s2.begin(); j!=s2.end() && i<h+t; j++) {
            if (i==h) cout << endl;
            cout << *j + 1 << ' ';
            i++;
        }
        return true;
    }
    return false;*/
}

int main()
{
    cin >> n >> m >> h >> t;
    vector<pair<int, int> > edges;
    graph.resize(n);
    f = new int[n];
    for (int i=0; i<n; i++) f[i] = 0;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
        edges.push_back(pair<int, int>(a-1, b-1));
    }
    bool res = false;
    for (int i=0; i<edges.size(); i++) {
        if (res = try_edge(edges[i].first, edges[i].second)) break;
        if (res = try_edge(edges[i].second, edges[i].first)) break;
    }
    if (!res) cout << "NO";
    return 0;
}