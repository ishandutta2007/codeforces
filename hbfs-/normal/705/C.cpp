#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>
using namespace std ;
 
typedef long long LL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const double inf = 0x3f3f3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
const int dr[] = {0, 0, -1, 1};
const int dc[] = {-1, 1, 0, 0};
int n, m;
inline bool is_in(int r, int c){
    return r >= 0 && r < n && c >= 0 && c < m;
}
queue<int> q[maxn];
set<int> sets;
set<int> :: iterator it;
 
int main(){
    scanf("%d %d", &n, &m);
    int ans = 0, cnt = 0, x, y;
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &x, &y);
        if(1 == x){
            q[y].push(cnt);
            sets.insert(cnt++);
            ++ans;
        }
        else if(2 == x){
            while(!q[y].empty()){
                int u = q[y].front();  q[y].pop();
                if(sets.count(u)){
                    --ans;
                    sets.erase(u);
                }
            }
        }
        else if(3 == x){
            for(it = sets.begin(); it != sets.end(); ){
                if(*it < y){
                    sets.erase(it++);
                    --ans;
                }
                else break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}