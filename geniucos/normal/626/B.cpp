#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, ap[10], sol[400];
char sir[500];

int cod (char c)
{
    if (c == 'R') return 0;
    if (c == 'G') return 1;
    return 2;
}
char cod2 (int val)
{
    if (val ==0) return 'R';
    if (val==1)return 'G';
    return 'B';
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
gets (sir + 1);
for (int i=1; i<=N; i++)
    ap[cod(sir[i])] ++;
if (ap[0] * ap[1]*ap[2]>0)
    sol['R'] =sol['B']=sol['G']=1;
else
if(ap[0]==0&&ap[1]==0) sol[cod2(2)]=1;
else
if(ap[0]==0&&ap[2]==0) sol[cod2(1)]=1;
else
if(ap[1]==0&&ap[2]==0) sol[cod2(0)]=1;
else
{
    int j=-1, k=-1;
    for(int i=0;i<3;i++)
        if(ap[i]==0)sol[cod2(i)]=1;
        else
        {
            if(j==-1) j=i;
            else k=i;
        }
    if (ap[k]>=2) sol[cod2(j)]=1;
    if(ap[j]>=2)sol[cod2(k)]=1;
}
for(int i=0;i<250;i++)
    if(sol[i])printf("%c", i);
printf("\n");

return 0;
}