#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct segm { int r; int a; int b; };

struct point {
    int x; int y;
    point(int x, int y):x(x), y(y) {}
};

bool compare1(segm a, segm b) {
    if (a.r != b.r) return (a.r<b.r);
    else return (a.a<b.a);
}

bool compare2(point a, point b) {
    if (a.x != b.x) return (a.x<b.x);
    else return (a.y<b.y);
}

vector<vector<int> > graph;

void add_edge(int i, int j) {
    graph[i].push_back(j);
    graph[j].push_back(i);
}

int main()
{
    int x0, y0, x1, y1, n;
    vector<segm> segments;
    vector<point> points;
    points.reserve(100000);
    cin >> x0 >> y0 >> x1 >> y1 >> n;
    segments.resize(n);
    for (int i=0; i<n; i++) cin >> segments[i].r >> segments[i].a >> segments[i].b;
    sort(segments.begin(), segments.end(), compare1);
    int now = 0, right = 0;
    for (int i=0; i<n; i++) {
        if (now != segments[i].r) {
            now = segments[i].r;
            right = 0;
        }
        for (int j=max(segments[i].a, right+1); j<=segments[i].b; j++) points.push_back(*(new point(now, j)));
        if (segments[i].b > right) right = segments[i].b;
    }
    graph.resize(points.size());
    for (int i=0; i<points.size(); i++) graph[i].reserve(8);
    for (int i=0; i<points.size(); i++) {
        vector<point>::iterator a;
        a = lower_bound(points.begin(), points.end(), point(points[i].x-1, points[i].y-1), compare2);
        if (a->x == points[i].x-1 && a->y == points[i].y-1) add_edge(int(a-points.begin()), i);
        a = lower_bound(points.begin(), points.end(), point(points[i].x, points[i].y-1), compare2);
        if (a->x == points[i].x && a->y == points[i].y-1) add_edge(int(a-points.begin()), i);
        a = lower_bound(points.begin(), points.end(), point(points[i].x+1, points[i].y-1), compare2);
        if (a->x == points[i].x+1 && a->y == points[i].y-1) add_edge(int(a-points.begin()), i);
        a = lower_bound(points.begin(), points.end(), point(points[i].x-1, points[i].y), compare2);
        if (a->x == points[i].x-1 && a->y == points[i].y) add_edge(int(a-points.begin()), i);
    }
    vector<int> time(points.size());
    vector<bool> used(points.size());
    queue<int> q;
    q.push((int)(lower_bound(points.begin(), points.end(), point(x0, y0), compare2) - points.begin()));
    used[q.front()] = true;
    while(!q.empty()) {
        int v=q.front();
        q.pop();
        for (int i=0; i<graph[v].size(); i++) {
            if (!used[graph[v][i]]) {
                q.push(graph[v][i]);
                time[graph[v][i]] = time[v] + 1;
                used[graph[v][i]] = true;
            }
        }
    }
    int k = time[(int)(lower_bound(points.begin(), points.end(), point(x1, y1), compare2) - points.begin())];
    if (k == 0) cout << -1;
    else cout << k;
}