#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <set>

typedef std::pair<char, char> coord;

const char dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const char dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool board[8][8], vis[8][8];
int n;
std::vector<std::pair<coord, coord>> ans, path;
std::set<std::pair<coord, coord>> pool;

bool dfs(coord x, coord y)
{
    if (x == y) return true;
    vis[x.first][x.second] = true;
    for (char i = 0; i < 8; ++i)
    {
        coord p = std::make_pair(x.first + dx[i], x.second + dy[i]);
        if (p.first >= 0 && p.first < 8 && p.second >= 0 && p.second < 8 && vis[p.first][p.second] == false)
        {
            path.push_back(std::make_pair(x, p));
            if (dfs(p, y) == true)
                return true;
            path.pop_back();
        }
    }
    return false;
}

void transport(char s, char t)
{
    memset(vis, 0x00, sizeof(vis));
    dfs(std::make_pair(s % 8, s / 8), std::make_pair(t % 8, t / 8));
    for (auto m : path)
        pool.insert(m);
    path.clear();
    std::vector<std::pair<coord, coord>> tmp;
    while (!pool.empty())
    {
        for (auto m : pool)
            if (board[m.first.first][m.first.second] == true && board[m.second.first][m.second.second] == false)
            {
                tmp.push_back(m);
                ans.push_back(m);
                board[m.first.first][m.first.second] = false;
                board[m.second.first][m.second.second] = true;
                //std::cout << m.first.first+'a' << m.first.second+'1' << '-' << m.second.first+'a' << m.second.second+'1' << '\n';
            }
        for (auto m : tmp)
            pool.erase(m);
        tmp.clear();
    }
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        char x = s[0] - 'a',
             y = s[1] - '1';
        board[x][y] = true;
    }
    for (int i = 0; i < n; ++i)
        if (board[i % 8][i / 8] == false)
            for (int j = 63; j >= 0; --j)
                if (board[j % 8][j / 8] == true)
                {
                    transport(j, i);
                    break;
                }
    std::cout << ans.size() << '\n';
    for (auto m : ans)
        std::cout << (char)(m.first.first+'a') << (char)(m.first.second+'1') << '-' << (char)(m.second.first+'a') << (char)(m.second.second+'1') << '\n';
}