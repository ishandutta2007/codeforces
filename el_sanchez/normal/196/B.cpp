#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

typedef vector <int> vi;
typedef long long ll;
typedef pair <int, int> pii;

const int maxS = 1510;

int h, w;
char s[maxS][maxS];
char was[maxS][maxS];
int mx[maxS][maxS];
int my[maxS][maxS];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void go( int x, int y, int rx, int ry )
{
  if (s[x][y] == '#')
    return;
  if (was[x][y])
  {
    if (rx != mx[x][y] || ry != my[x][y])
    {
      //printf("%d, %d : %d, %d [end]\n", x, y, rx, ry);
      puts("Yes");
      exit(0);
    }
    return;
  }
  //printf("%d, %d : %d, %d\n", x, y, rx, ry);
  was[x][y] = 1;
  mx[x][y] = rx;
  my[x][y] = ry;

  forn(k, 4)
    go((x + dx[k] + h) % h, (y + dy[k] + w) % w, rx + dx[k], ry + dy[k]);
}

int main()
{
  scanf("%d%d ", &h, &w);
  forn(i, h)
    gets(s[i]);

  int sx = -1, sy = -1;
  forn(i, h)
    forn(j, w)
      if (s[i][j] == 'S')
        sx = i, sy = j, s[i][j] = '.';
  go(sx, sy, sx, sy);
  puts("No");
  return 0;
}