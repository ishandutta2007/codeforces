#include<cstdio>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
int l, ok, n, nr, ap[5009], st[5009], app[5009];
char A[5009][5009];
vector < int > cic;
void dfs (int nod)
{
    ap[nod] = 1;
    st[++l]=nod;
    app[nod]=l;
    for (int i=1; i<=n; i++)
        if (A[nod][i] == '1')
        {
            if (ap[i] == 0) dfs (i);
            else
            if (ok == 0 && app[i] != 0)
            {
                for (int j=app[i]; j<= l; j++)
                    cic.push_back(st[j]);
                ok=1;
            }
        }
    app[nod]=0;
    l--;
}
void det(vector < int > cc)
{
    if (A[cc[0]][cc[2]] == '0')
    {
        printf ("%d %d %d\n", cc[0], cc[1], cc[2]);
        return ;
    }
    cc.erase (cc.begin()+1);
    det(cc);
}
int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
srand(time(0));
scanf ("%d\n", &n);
for (int i=1; i<=n; i++)
    gets(A[i]+1);
if (n<=2)
{
    printf ("-1\n");
    return 0;
}
for (int i=1; i<=n; i++)
    if (ap[i]==0)
    {
        dfs(i);
        if (ok) break;
    }
if (ok==0)
{
    printf ("-1\n");
    return 0;
}
det(cic);
return 0;
}