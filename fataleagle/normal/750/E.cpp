#include <bits/stdc++.h>

using namespace std;

int N, Q;
char S[200005];
int nxt[10][200005];
int cnt[10][200005];

int get(int x, int l, int r)
{
    return cnt[x][r]-cnt[x][l-1];
}

struct node
{
    int s[5][5];
} seg[1<<19];

node make(int v)
{
    node n;
    memset(n.s, 0x3f, sizeof n.s);
    if(v==2)
    {
        n.s[0][0]=1;
        n.s[0][1]=0;
        n.s[1][1]=0;
        n.s[2][2]=0;
        n.s[3][3]=0;
        n.s[4][4]=0;
    }
    else if(v==0)
    {
        n.s[0][0]=0;
        n.s[1][1]=1;
        n.s[1][2]=0;
        n.s[2][2]=0;
        n.s[3][3]=0;
        n.s[4][4]=0;
    }
    else if(v==1)
    {
        n.s[0][0]=0;
        n.s[1][1]=0;
        n.s[2][2]=1;
        n.s[2][3]=0;
        n.s[3][3]=0;
        n.s[4][4]=0;
    }
    else if(v==7)
    {
        n.s[0][0]=0;
        n.s[1][1]=0;
        n.s[2][2]=0;
        n.s[3][3]=1;
        n.s[3][4]=0;
        n.s[4][4]=0;
    }
    else if(v==6)
    {
        n.s[0][0]=0;
        n.s[1][1]=0;
        n.s[2][2]=0;
        n.s[3][3]=1;
        n.s[4][4]=1;
    }
    else
    {
        n.s[0][0]=0;
        n.s[1][1]=0;
        n.s[2][2]=0;
        n.s[3][3]=0;
        n.s[4][4]=0;
    }
    return n;
}

node combine(node a, node b)
{
    node c;
    for(int i=0; i<5; i++)
    {
        for(int j=i; j<5; j++)
        {
            c.s[i][j]=0x3f3f3f3f;
            for(int k=i; k<=j; k++)
                c.s[i][j]=min(c.s[i][j], a.s[i][k]+b.s[k][j]);
        }
    }
    return c;
}

void build(int idx, int begin, int end)
{
    if(begin==end)
        seg[idx]=make(S[begin]-'0');
    else
    {
        int mid=(begin+end)/2;
        build(idx*2, begin, mid);
        build(idx*2+1, mid+1, end);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

node query(int idx, int begin, int end, int l, int r)
{
    if(r<begin || end<l)
        return make(0);
    if(l<=begin && end<=r)
        return seg[idx];
    int mid=(begin+end)/2;
    return combine(query(idx*2, begin, mid, l, r),
                   query(idx*2+1, mid+1, end, l, r));
}

int main()
{
    scanf("%d%d", &N, &Q);
    scanf("%s", S+1);
    build(1, 1, N);
    while(Q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int ans=query(1, 1, N, l, r).s[0][4];
        if(ans>=0x3f3f3f3f)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}