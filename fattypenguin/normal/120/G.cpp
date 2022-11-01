#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int V = 500;

int n, m, turn;
int a[V][2], b[V][2];
int c[V], Q[9000000];
int d[V][V];

vector<int> ans[V];
char name[V][V];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&turn);
    for (int i=0;i<n;i++)
        scanf("%d%d%d%d",&a[i][0],&b[i][0],&a[i][1],&b[i][1]);
    
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        scanf("%s",name[i]);
        scanf("%d",&c[i]);
    }
    
    memset(d, 0, sizeof(d));
    for (int i=0;i<m;i++) Q[i] = i;
    
    int now = 0, i = 0; 
    int head = 0, tail = m, left = turn;
    while (head < tail)
    {
        int k = Q[head];
        int need = max(1, c[k]-(a[i][now]+b[i][now^1])-d[i][k]);
        if (need <= left)
        {
            left -= need;
            ans[i].push_back(k);
            if (left == 0)
            {
                left = turn;
                i++;
                if (i == n){
                    now ^= 1;
                    i = 0;
                }
            }
        }else
        {
            Q[tail++] = k;
            d[i][k] += left;
            
            left = turn;
            i++;
            if (i == n){
                now ^= 1;
                i = 0;
            }
        }
        //printf("head is %d %d\n",head, tail);
        head++;
    }
    
    for (int i=0;i<n;i++)
    {
        printf("%d ",ans[i].size());
        for (int j=0;j<ans[i].size();j++)
        {
            if (j) printf(" ");
            printf("%s",name[ ans[i][j] ]);
        }
        puts("");
    }
}