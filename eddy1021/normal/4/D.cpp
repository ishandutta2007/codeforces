#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int> tii;
typedef tuple<int, int, int> tiii;
typedef long long ll;

const int MAXN = 5010;

int n, bw, bh;
int w[MAXN], h[MAXN];
vector<tiii> env;
int dp[MAXN], prv[MAXN];

void print(int id)
{
    if(id == -1) return ;
    print(prv[id]);
    printf("%d ", get<2>(env[id]));
}

int main()
{
    scanf("%d%d%d", &n, &bw, &bh);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", w+i, h+i);
        if(w[i] > bw && h[i] > bh)
            env.push_back(tiii(w[i], h[i], i));
    }
    sort(env.begin(), env.end());
    int ans = 0, aid = -1;
    for(int i = 0; i < (int)env.size(); i++)
    {
        //printf("now w %d h %d id %d\n", get<0>(env[i]), get<1>(env[i]), get<2>(env[i]));
        int mx = 0, pid = -1;
        for(int j = 0; j < i; j++)
            if(get<0>(env[j]) < get<0>(env[i]) &&
               get<1>(env[j]) < get<1>(env[i]) &&
               mx < dp[j])
                mx = dp[j], pid = j;
        dp[i] = mx+1, prv[i] = pid;
        //printf("dp %d\n", dp[i]);
        if(dp[i] > ans)
            ans = dp[i], aid = i;
    }
    printf("%d\n", ans);
    print(aid);
    puts("");
}