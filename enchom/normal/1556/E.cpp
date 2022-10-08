#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long llong;

struct Node
{
    llong sum;
    llong maxPref, minPref;
};

Node Merge(Node A, Node B)
{
    Node C;

    C.sum = A.sum + B.sum;
    C.maxPref = max(A.maxPref, A.sum + B.maxPref);
    C.minPref = min(A.minPref, A.sum + B.minPref);

    return C;
}

int n, q;
int a[200111];
int b[200111];

Node IT[800111];
int LEAFOFFSET = 1;

void show(Node A)
{
    printf("%lld; pref: %lld; %lld\n", A.sum, A.minPref, A.maxPref);
}

Node buildNode(int ver, int L, int R, int l, int r)
{
    //printf("Building %d - %d\n", L, R);

    if (L > r || R < l)
    {
        //printf("Empty hit\n");
        //show(IT[0]);

        return IT[0];
    }
    else if (L >= l && R <= r)
    {
        //printf("Full hit\n");
        //show(IT[ver]);
        return IT[ver];
    }
    else
    {
        Node lft = buildNode(2*ver, L, (L+R)/2, l, r);
        Node rt = buildNode(2*ver+1, (L+R)/2+1, R, l, r);

        //printf("Building parts at %d - %d\n", L, R);
        //printf("sums are %lld; %lld\n", lft.sum, rt.sum);
        //show(Merge(lft, rt));
        return Merge(lft, rt);
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);

    int i, j;

    memset(IT, 0, sizeof(IT));

    scanf("%d %d", &n, &q);

    LEAFOFFSET = 1;
    while(LEAFOFFSET < n)
        LEAFOFFSET *= 2;
    LEAFOFFSET--;

    for (i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d", &b[i]);
    }

    for (i=1;i<=n;i++)
    {
        llong v = b[i] - a[i];

        IT[i+LEAFOFFSET].sum = v;
        IT[i+LEAFOFFSET].minPref = v;
        IT[i+LEAFOFFSET].maxPref = v;
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        IT[i] = Merge(IT[2*i], IT[2*i+1]);
    }

    for (i=1;i<=q;i++)
    {
        int l, r;

        scanf("%d %d", &l, &r);

        Node v = buildNode(1, 1, LEAFOFFSET+1, l, r);

        if (v.sum != 0 || v.minPref < 0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n", v.maxPref);
        }
    }

    return 0;
}