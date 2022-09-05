#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<map>

using namespace std;

int Q, v, act, ras, p, u, mij, n, a[100009], rmq[100009][20];
char lg[100009];

map < int , long long > ans;

int gcd (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int G (int st, int dr)
{
    int p = lg[dr-st+1];
    return gcd(rmq[st][p], rmq[dr-(1<<p)+1][p]);
}

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &n);
for (int i=1; i<=n; i++)
    scanf ("%d", &a[i]);
for (int i=n;i>=1;i--)
{
    rmq[i][0]=a[i];
    for (int j=1; (1<<j) + i -1 <=n; j++)
        rmq[i][j] = gcd(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
}

lg[1]=0;
for (int i=2; i<=n; i++)
{
    lg[i]=lg[i-1];
    if ((1<<(lg[i]+1)) <=i) lg[i]++;
}

for (int i=1; i<=n; i++)
{
    int j=i;
    while(1)
    {
        act = G(i, j);
        if (act == 1)
        {
            ras = n;
            ans[1] += n - j + 1;
            break;
        }
        p=j;
        u=n;
        while (p<=u)
        {
            mij = (p+u)>>1;
            if (G(i, mij) == act)
            {
                ras = mij;
                p=mij+1;
            }
            else u=mij-1;
        }
//        j=ras;
        /////[i,j], ..., [i,ras] = act;
        ans[act] += ras-j+1;
        j = ras + 1;
        if (j>n) break;
    }
}
scanf ("%d",&Q);
while(Q)
{
    Q--;
    scanf ("%d",&v);
    printf ("%I64d\n", ans[v]);
}
return 0;
}