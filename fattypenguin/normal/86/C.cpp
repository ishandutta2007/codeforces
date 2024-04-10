#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll  MOD = 1000000009ll;
const int maxn = 100*15 + 16;

struct node
{
    int next[4];
    int suf,count,dep;
    bool dan;
} tree[maxn];

ll F[1007][107][11];
int n,m,len,last,queue[maxn];
char str[128],temp[128];

inline int tr(char c)
{
    if (c == 'A') return 0;
    if (c == 'T') return 1;
    if (c == 'C') return 2;
    if (c == 'G') return 3;
}

int insert(char *s,int len)
{
    int now = 1;
    for (int i = 0;i < len;++i)
        if (tree[now].next[tr(s[i])])
            now = tree[now].next[tr(s[i])];
        else
        {
            tree[now].next[tr(s[i])] = last;
            now = last++;
        }
    ++tree[now].count;
    tree[now].dep = len;
    tree[now].dan = true;
    return now;
}

int min(int a,int b)
{
    return a<b?a:b;
}

void buildTrie()
{
    int front = 0,rear = 0;
    queue[rear++] = 1;
    while (front < rear)
    {
        int now = queue[front++];
        tree[now].dan = tree[now].dan || tree[tree[now].suf].dan;
        tree[now].dep = max(tree[now].dep,tree[tree[now].suf].dep);
        for (int i = 0;i < 4;++i)
            if (tree[now].next[i])
            {
                queue[rear++] = tree[now].next[i];
                tree[tree[now].next[i]].suf = tree[tree[now].suf].next[i];
            }
            else
                tree[now].next[i] = tree[tree[now].suf].next[i];
    }
}

void dp()
{
    memset(F,0,sizeof(F));
    F[0][1][0] = 1;
    for (int i = 0;i < n;++i)
        for (int j = 1;j < last;++j)
            for (int k = 0;k <= 10;++k)
                {
                    for (int r = 0;r < 4;++r)
                    {
                        if (tree[tree[j].next[r]].dep >= k+1)
                        {
                            int now = tree[j].next[r];
                        //    while (tree[now].dep >= k+1)
                          //  {
                                F[i+1][now][0] = (F[i+1][now][0] + F[i][j][k])%MOD;
                            //    now = tree[now].suf;
                           // }
                        }
                        else if (k < 10)
                            F[i+1][tree[j].next[r]][k+1] = (F[i+1][tree[j].next[r]][k+1] + F[i][j][k])%MOD;
                    }
                }
}

int main()
{
    cin >> n >> m;
    memset(tree,0,sizeof(tree));
    for (int i = 0;i < 4;++i)
        tree[0].next[i] = 1;
    last = 2;
    for (int i = 0;i < m;++i)
    {
        scanf("%s",temp);
        insert(temp,strlen(temp));
    }
    buildTrie();
    tree[1].suf = 1;
    dp();
    ll ans = 0;
    for (int i = 1;i < last;++i)
        ans = (ans + F[n][i][0]) % MOD;
    cout << (ans+MOD)%MOD << endl;
    return 0;
}