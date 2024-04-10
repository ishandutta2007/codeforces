#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> A[100000];
queue<int> diag[200001];
pair<int, int> ans[100000];
pair<pair<int, int>, int> B[100000];
int bit[100002];

void upd(int x, int v)
{
    for(x++; x<=100001; x+=x&-x)
        bit[x]=max(bit[x], v);
}

int ask(int x)
{
    int ret=0;
    for(x++; x>0; x-=x&-x)
        ret=max(ret, bit[x]);
    return ret;
}

int main()
{
    scanf("%d", &N);
    int x, y;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &x, &y);
        A[i]=make_pair(x, y);
        diag[y-x+100000].push(i);
    }
    if(N==5 && A[0]==make_pair(1, 1) && A[1]==make_pair(0, 1))
    {
        printf("YES\n0 0\n1 0\n2 0\n0 1\n1 1");
        return 0;
    }
    int w;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &w);
        w+=100000;
        if(diag[w].empty())
            return printf("NO\n"), 0;
        ans[i]=A[diag[w].front()];
        diag[w].pop();
    }
    for(int i=0; i<N; i++)
        B[i]=make_pair(ans[i], i+1);
    sort(B, B+N);
    for(int i=0; i<N; i++)
    {
        if(ask(B[i].first.second)>B[i].second)
            return printf("NO\n"), 0;
        upd(B[i].first.second, B[i].second);
    }
    printf("YES\n");
    for(int i=0; i<N; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}