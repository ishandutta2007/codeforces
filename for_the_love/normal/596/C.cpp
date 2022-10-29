#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;

struct Pnode{
    int x, y;
    bool operator < (const Pnode &A)const{
        if (x == A.x) return y < A.y;
        return x < A.x;
    }
} p[100005];

inline int lowbit(int x){return x & -x;}

int b[100005];

void add(int x, int y){
    for (; x <= 100001; x += lowbit(x))
        b[x] = max(b[x], y);
}

int query(int x){
    int ret = -1;
    for (; x; x -= lowbit(x))
        ret = max(ret, b[x]);
    return ret;
}

vector <int> vec[200005];
int l[200005], ans[100005];

int main(){
    int n, w;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &p[i].x, &p[i].y);

    sort(p, p + n);

    for (int i = 0; i < n; i++){
        scanf("%d", &w);
        vec[w + 100000].push_back(i);
    }

    memset(b, -1, sizeof(b));

    for (int i = 0; i < n; i++){
        int w = p[i].y - p[i].x + 100000;
        if (l[w] < vec[w].size()){
            if (query(p[i].y + 1) > vec[w][l[w]] + 1){
                puts("NO");
                return 0;
            }
            add(p[i].y + 1, vec[w][l[w]] + 1);
            ans[vec[w][l[w]]] = i;
            l[w]++;
        }else{
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    for (int i = 0; i < n; i++)
        printf("%d %d\n", p[ans[i]].x, p[ans[i]].y);
}