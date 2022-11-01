#include <bits/stdc++.h>
using namespace std;

int n, m, rj = 0;
char slova [300005];
vector <vector <int> > graf;
bool dag = 1;
bool bio [300005];
bool posj [300005];
int dp [300005] [30];
char tr;

void rek (int x)
{
    if (posj [x]) {dag = 0; return;}
    if (bio [x]) return;
    posj [x] = 1;
    bio [x] = 1;
    for (int obidi = 0; obidi < graf [x].size(); obidi++)
    {
        rek (graf [x] [obidi]);
        if (!dag) return;
    }
    posj [x] = 0;
}

int din (int x)
{
    if (dp [x] [tr - 'a'] != -1) return dp [x] [tr - 'a'];
    int ret = 0;
    for (int k = 0; k < graf [x].size(); k++) ret = max (ret, din (graf [x] [k]));
    if (tr == slova [x]) ret++;
    return dp [x] [tr - 'a'] = ret;
}

int main()
{
    memset (dp, -1, sizeof dp);
    vector <int> vi;
    scanf("%d%d", &n, &m);
    graf.insert(graf.begin(), n, vi);
    scanf("%s", slova);
    int a, b;
    for (int up = 0; up < m; up++)
    {
        scanf("%d%d", &a, &b);
        a--; b--;
        graf [b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        rek (i);
        if (!dag) break;
    }
    if (!dag) {printf("-1"); return 0;}

    for (char i = 'a'; i <= 'z'; i++)
    {
        tr = i;
        for (int j = 0; j < n; j++)
        {
            if (dp [j] [i - 'a'] == -1) din (j);
            if (dp [j] [i - 'a'] > rj) rj = dp [j] [i - 'a'];
        }
    }
    printf("%d", rj);
    return 0;
}