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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
char buf[1000000];
vector<int> a, adj[10010];
int f[10010], d[10010], q[10010];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    scanf("%s", buf);
    int len = strlen(buf), cnt = 0, prev;
    char op;
    bool flag = false;
    for (int i = 0; i < len; i++) {
        if (buf[i] == ':') {
            i++;
            flag = true;
            continue;
        }
        if (!flag) {
            if (buf[i] == '_')
                cnt++;
            else if (cnt) {
                a.push_back(cnt);
                cnt = 0;
            }
            continue;
        }
        if (buf[i] == '_')
            cnt++;
        else if (buf[i] == '<' || buf[i] == '>') {
            prev = cnt;
            op = buf[i];
            cnt = 0;
        }
        else if (op == '<') {
            adj[prev].push_back(cnt);
            d[cnt]++;
            cnt = 0;
        }
        else {
            adj[cnt].push_back(prev);
            d[prev]++;
            cnt = 0;
        }
    }
    int l = 1, r = 0;
    for (int i = 1; i <= 10000; i++)
        if (d[i] == 0) q[++r] = i;
    while (l <= r) {
        int x = q[l++];
        for (int i = 0; i < adj[x].size(); i++) {
            int y = adj[x][i];
            f[y] = max(f[y], f[x] + 1);
            if (--d[y] == 0) q[++r] = y;
        }
    }
    if (*max_element(f + 1, f + 10001) > 9 || r != 10000)
        printf("false\n");
    else {
        for (int i = 0; i < a.size(); i++) printf("%d", f[a[i]]);
        printf("\n");
    }
	return 0;
}