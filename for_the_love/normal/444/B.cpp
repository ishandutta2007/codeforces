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
const int N = 1e5 + 7;
const int MOD = 1e9 + 9;
const int INF = 1e9 + 7;
vector <int> v;
int a[N], b[N], n, d, pos[N];
LL x;
int getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
int main(){
    cin >> n >> d >> x;
    initAB();
    for (int i = 0; i < n; i++) pos[a[i]] = i;
    for (int i = 0; i < n; i++) if (b[i]) v.PB(i);
    for (int i = 0; i < n; i++)
    if (d < 360){
        int ans = 0;
        for (int j = 0; j < v.size(); j++)
        if (i >= v[j]) ans = max(ans, a[i - v[j]]);
        printf("%d\n", ans);
    }else{
        int flag = 0;
        for (int j = n; j > 0; j--)
        if (i >= pos[j] && b[i - pos[j]]){
            printf("%d\n", j);
            flag = 1;
            break;
        }
        if (!flag) puts("0");
    }

}