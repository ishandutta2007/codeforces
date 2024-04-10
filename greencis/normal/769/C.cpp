#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};
char let[4] = {'D', 'L', 'R', 'U'};
int g[1010][1010];
int dist[1010][1010];
int used[1010][1010];
int pr[1010][1010];
vector<char> ans;
queue< pii > q;
pii start;

char s[1010];
int n, m, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            pr[i][j] = 100;
            dist[i][j] = 1e9;
            if (s[j] == '*')
                g[i][j] = -1;
            else if (s[j] == '.')
                g[i][j] = 0;
            else{
                start = make_pair(i, j);
                g[i][j] = 1;
            }
        }
    }

    bool pos = false;
    pii curv = start;
    for (int i = 0; i < 4; i++){
        if (curv.f + dy[i] >= 0 && curv.f + dy[i] < n && curv.s + dx[i] >=0 && curv.s + dx[i] < m && g[curv.f + dy[i]][curv.s + dx[i]] != -1)
            pos = true;
    }

    if (k % 2 != 0 || !pos){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    q.push(start);
    used[start.f][start.s] = true;
    dist[start.f][start.s] = 0;

    while (!q.empty()){
        curv = q.front();
        for (int i = 0; i < 4; i++)
            if (curv.f + dy[i] >= 0 && curv.f + dy[i] < n && curv.s + dx[i] >=0 && curv.s + dx[i] < m && g[curv.f + dy[i]][curv.s + dx[i]] != -1)
            {
                if (dist[curv.f][curv.s] + 1 <= dist[curv.f + dy[i]][curv.s + dx[i]])
                    pr[curv.f + dy[i]][curv.s + dx[i]] = min(pr[curv.f + dy[i]][curv.s + dx[i]], 3 - i);
                if (!used[curv.f + dy[i]][curv.s + dx[i]]){
                    q.push(make_pair(curv.f + dy[i], curv.s + dx[i]));
                    used[curv.f + dy[i]][curv.s + dx[i]] = true;
                    dist[curv.f + dy[i]][curv.s + dx[i]] = dist[curv.f][curv.s] + 1;
                }
            }

        q.pop();
    }

    curv = start;
    while(dist[curv.f][curv.s] < k){
        for(int i = 0; i < 4; i++){
            if (curv.f + dy[i] >= 0 && curv.f + dy[i] < n && curv.s + dx[i] >=0 && curv.s + dx[i] < m && g[curv.f + dy[i]][curv.s + dx[i]] != -1){
                ans.push_back(let[i]);
                curv = make_pair(curv.f + dy[i], curv.s + dx[i]);
                k--;
                break;
            }
        }
    }

    while (k != 0){
        int dir = pr[curv.f][curv.s];
        ans.push_back(let[dir]);
        curv = make_pair(curv.f + dy[dir], curv.s + dx[dir]);
        k--;
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    cout << endl;
    return 0;
}