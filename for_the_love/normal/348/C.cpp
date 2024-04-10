//#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
const int BLOCKSIZE = 333;
bool bigcontain[BLOCKSIZE][N];
int bigid[N], bigs[BLOCKSIZE], ncross[BLOCKSIZE][N];
long long a[N], s[N], sign[N];
vector<int> contain[N];
vector<int> belong[N];
int n, m, q, cnt, nbig, x;
int main(){
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++){
        cin >> cnt;
        if (cnt > BLOCKSIZE){
            bigid[i] = nbig;
            bigs[nbig++] = i;
        }else bigid[i] = -1;
        for (int j = 0; j < cnt; j++){
            cin >> x;
            x--;
            if (bigid[i] != -1) bigcontain[nbig - 1][x] = 1;
            contain[i].push_back(x);
            belong[x].push_back(i);
            s[i] += a[x];
        }
    }
    for (int i = 0; i < nbig; i++)
    for (int j = 0; j < m; j++)
    for (int k = 0; k < contain[j].size(); k++)
    if (bigcontain[i][contain[j][k]]) ncross[i][j]++;

    while (q--){
        char ch;
        long long x, y;
        scanf(" %c ", &ch);
        if (ch == '?'){
            cin >> x; x--;
            long long ans = 0;
            if (bigid[x] == -1){
                for (int i = 0; i < contain[x].size(); i++) ans += a[contain[x][i]];
                for (int i = 0; i < nbig; i++) ans += sign[bigs[i]] * (long long)ncross[i][x];
            }else{
                ans = s[x];
                for (int i = 0; i < nbig; i++) ans += sign[bigs[i]] * (long long)ncross[i][x];
            }
            cout << ans << endl;
        }else{
            cin >> x >> y; x--;
            if (bigid[x] == -1){
                for (int i = 0; i < contain[x].size(); i++) a[contain[x][i]] += y;
                for (int i = 0; i < nbig; i++) s[bigs[i]] += (long long)ncross[i][x] * y;
            }else sign[x] += y;
        }
    }
}