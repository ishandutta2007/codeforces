#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int code (char c)
{
    if (c == 'X') return 0;
    if (c == 'A') return 1;
    if (c == 'B') return 2;
    return 3;
}

struct conf
{
    int a[2][2];
    void Read ()
    {
        char c1, c2, c3, c4;
        scanf ("%c%c\n%c%c\n", &c1, &c2, &c3, &c4);
        a[0][0] = code (c1), a[0][1] = code (c2);
        a[1][0] = code (c3), a[1][1] = code (c4);
    }
    conf (int _a, int _b, int _c, int _d) {a[0][0] = _a, a[0][1] = _b, a[1][0] = _c, a[1][1] = _d;}
    conf () {}
    pair < int, int > neighbors ();
    bool operator < (const conf &other) const
    {
        for (int i=0; i<2; i++)
            for (int j=0; j<2; j++)
                if (a[i][j] != other.a[i][j]) return a[i][j] < other.a[i][j];
        return 0;
    }
}v[30], conf1, conf2;

int nr;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
map < conf, int > mp;
bool ap[30];

void Init ()
{
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            for (int k=0; k<4; k++)
                for (int p=0; p<4; p++)
                    if (i != j && i != k && i != p && j != k && j != p && k != p)
                        v[++nr] = conf (i, j, k, p), mp[v[nr]] = nr;
}

pair < int , int > conf :: neighbors ()
{
    pair < int , int > ans = make_pair (-1, -1);
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            if (a[i][j] != 0)
            {
                for (int k=0; k<4; k++)
                    if (i + dx[k] >= 0 && i + dx[k] < 2 && j + dy[k] >= 0 && j + dy[k] < 2 && a[i + dx[k]][j + dy[k]] == 0)
                    {
                        swap (a[i][j], a[i + dx[k]][j + dy[k]]);
                        int curr = mp[conf (a[0][0], a[0][1], a[1][0], a[1][1])];
                        if (ans.first == -1) ans.first = curr;
                        else ans.second = curr;
                        swap (a[i][j], a[i + dx[k]][j + dy[k]]);
                    }
            }
    return ans;
}

void dfs (int nod)
{
    ap[nod] = 1;
    pair < int , int > curr = v[nod].neighbors ();
    if (ap[curr.first] == 0) dfs (curr.first);
    if (ap[curr.second] == 0) dfs (curr.second);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Init ();
conf1.Read ();
conf2.Read ();
dfs (mp[conf1]);
if (ap[mp[conf2]]) printf ("YES\n");
else printf ("NO\n");

return 0;
}