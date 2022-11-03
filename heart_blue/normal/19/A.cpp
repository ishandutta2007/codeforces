#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 1;
const int N = 3e3;
class Team
{
public:
    int score, miss, goal;
    int num;
    string name;
    Team() :score(0), miss(0), goal(0){}
    Team(int _s, int _d, int _g, int _num, string _n) :score(_s), miss(_d), goal(_g), num(_num), name(_n) {}
    bool operator < (Team &t)
    {
        if (score != t.score) return score > t.score;
        if (goal - miss != t.goal - t.miss) return goal - miss > t.goal - t.miss;
        return goal > t.goal;
    }
};
vector<Team> vt;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    map<string, int> ms;
    int n;
    cin >> n;
    string str;
    vt.resize(n);
    for (int i = 0; i < n; i++) cin >> str, vt[i].name = str, vt[i].num = i, ms[str] = i;
    string s1, s2;
    int a, b;
    getline(cin, str);
    for (int i = 0; i < n*(n - 1) / 2; i++)
    {
        getline(cin, str);
        for (int i = 0; i < str.length(); i++) if (str[i] == ':' || str[i] == '-') str[i] = ' ';
        stringstream sin(str);
        sin >> s1 >> s2 >> a >> b;
        int x = ms[s1];
        int y = ms[s2];
        vt[x].goal += a;
        vt[x].miss += b;
        vt[y].goal += b;
        vt[y].miss += a;
        if (a == b)
        {
            vt[x].score++;
            vt[y].score++;
            continue;
        }
        if (a < b)  vt[y].score += 3;
        else vt[x].score += 3;

    }
    sort(vt.begin(), vt.end());
    vector<string> vs;
    for (int i = 0; i < n / 2; i++) vs.push_back(vt[i].name);
    sort(vs.begin(), vs.end());
    for (auto &it : vs) cout << it << endl;
    return 0;
}