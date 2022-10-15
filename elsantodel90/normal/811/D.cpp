#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define all(c) begin(c), end(c)

#define SIZE(c) int((c).size())
#define MACRO(code) do {code} while (false)

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};;

#define OPUESTA(dir) (((dir)+2)%4)
const string dirChar = "DRUL";

const int UNKNOWN = 0;
const int INVERTED = 1;
const int NORMAL = 2;

int inverted[4];

int currentX, currentY;

struct Position {int x,y;};

Position orderMove(int dir)
{
    cout << dirChar[dir] << endl;
    Position ret;
    cin >> ret.x >> ret.y;
    ret.x--;
    ret.y--;
    return ret;
}

void move(int dir)
{
    if (inverted[dir] == UNKNOWN)
    {
        Position newPos = orderMove(dir);
        if (newPos.x != currentX || newPos.y != currentY)
        {
            inverted[dir] = inverted[OPUESTA(dir)] = NORMAL;
            currentX = newPos.x;
            currentY = newPos.y;
            return;
        }
        inverted[dir] = inverted[OPUESTA(dir)] = INVERTED;
    }
    assert(inverted[dir] != UNKNOWN);
    if (inverted[dir] == INVERTED)
         dir = OPUESTA(dir);
    Position newPos = orderMove(dir);
    currentX = newPos.x;
    currentY = newPos.y;
}

vector<int> path;
vector<string> board;
int n,m;

bool dfs(int x, int y)
{
    if (board[x][y] == 'F')
        return true;
    board[x][y] = '*'; // We use * as visited mark, destroying the board
    forn(dir,4)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] != '*' && dfs(nx,ny))
        {
            path.push_back(dir);
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    board.resize(n);
    forn(i,n)
        cin >> board[i];
    
    assert(dfs(0,0));
    reverse(all(path));
    
    for (int dir : path)
        move(dir);
    return 0;
}