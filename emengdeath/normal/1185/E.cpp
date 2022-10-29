#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
vector<pair<int, int> > f[26];
pair<int, int> lastone;
char A[2001][2001], B[2001][2001];
int n, m;
int b[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<pair<int, int>, pair<int, int> > > ans;
int main()
{
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < 26; i ++)
            f[i].clear();
        lastone = make_pair(0, 0);
        ans.clear();
        for (int i =1; i <= n ; i ++)
            for (int j = 1; j <= m ; j ++){
                char c;
                scanf(" %c", &c);
                A[i][j] = c;
                B[i][j] = '.';
                if (c <= 'z' && 'a'<=c) f[c - 'a'].push_back(make_pair(i ,j));
            }
        bool sig = 1;
        for (int i = 25; i >= 0 && sig; i --)
            if (f[i].size() == 0 && lastone.first)
                ans.push_back(make_pair(lastone, lastone));
            else
                if (f[i].size()) {
                    sort(f[i].begin(), f[i].end());
                    lastone = f[i][0];
                    ans.push_back(make_pair(f[i][0], f[i][f[i].size() - 1]));
                }
        reverse(ans.begin(), ans.end());
        char c = 'a';
        for (auto u:ans) {
            if (u.first.first != u.second.first && u.first.second != u.second.second){
                sig = 0;
                break;
            }
            int j = 0;
            if (u.first == u.second) {
                B[u.first.first][u.first.second] = c;
                c ++;
                continue;
            }
            if (u.first.first < u.second.first) j = 1;
            if (u.first.first > u.second.first) j = 0;
            if (u.first.second < u.second.second) j =3;
            if (u.first.second > u.second.second) j = 2;
            pair<int, int> y = u.first;
            B[y.first][y.second] = c;
            while (y != u.second) {
                y.first += b[j][0];
                y.second += b[j][1];
                B[y.first][y.second] = c;
            }
            c ++;
        }
        for (int i = 1; i <= n && sig; i ++)
            for (int j = 1; j <= m && sig; j ++)
                if (A[i][j] != B[i][j]) sig = 0;
        if (!sig ){
            printf("NO\n");
            continue;
        }

        printf("YES\n");
        printf("%d\n", ans.size());
        for (auto u:ans)
            printf("%d %d %d %d\n", u.first.first, u.first.second, u.second.first, u.second.second);
    }
    return 0;
}