#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

queue <pair <int, int> > q;
pair <int, int> tr;
pair <int, int> novi;
int smjx [] = {-1, 0, 1, 0};
int smjy [] = {0, 1, 0, -1};
int rj [255] [255] = {{0}};
int d [255] [255] = {{0}};
bool bio [255] [255] = {{0}};
char po [255] [255];
int n, m, qu, p;

bool uvjet (int x1, int y1)
{
    if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) return 0;
    if (bio [x1] [y1]) return 0;
    if (po [x1] [y1] == '*') return 0;
    return 1;
}

int bfs (int x, int y)
{
    tr = make_pair (x, y);
    memset (bio, 0, sizeof bio);
    memset (d, -1, sizeof d);
    q.push (tr);
    bio [tr.first] [tr.second] = 1;
    d [tr.first] [tr.second] = 0;
    while (!q.empty ())
    {
        tr = q.front ();
        if (po [tr.first] [tr.second] != '.' && po [tr.first] [tr.second] != '*')
        {
            rj [x] [y] += ((po [tr.first] [tr.second] - 'A' + 1) * qu) / (1<<(d [tr.first] [tr.second]));//(d [tr.first] [tr.second] * 2);
            //cout << rj [x] [y];
        }
        q.pop();
        if (d [tr.first] [tr.second] > 25) continue;
        for (int nekii = 0; nekii < 4; nekii++)
        {
            novi.first = tr.first + smjx [nekii];
            novi.second = tr.second + smjy [nekii];
            if (uvjet (novi.first, novi.second))
            {
                q.push (novi);
                bio [novi.first] [novi.second] = 1;
                d [novi.first] [novi.second] = d [tr.first] [tr.second] + 1;
            }
        }
    }
    return rj [x] [y];
}

int main()
{
    string s;
    int rje = 0;
    cin >> n >> m >> qu >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            po [i] [j] = s [j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < m; l++)
        {
            if (po [k] [l] == '*') continue;
            if (bfs (k, l) > p) rje++;
            //cout << rj [k] [l];
        }
        //cout << endl;
    }
    cout << rje;
    return 0;
}