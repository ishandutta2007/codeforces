#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 5e2 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


int main(){
    int n, t, m, x, cnt = 0, ans = 0;
    scanf("%d%d%d", &n, &t, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        if (x > t) cnt = 0;
        else{
            cnt++;
            if (cnt >= m){
                ans++;
                cnt--;
            }
        }
    }
    cout << ans << endl;

}