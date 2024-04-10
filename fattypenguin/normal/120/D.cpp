#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int V = 100;
int n, m;
int mat[V][V], c[V][V], row[V], permu[V], sum[V], b[V];
int a[V];

int solve(int n,int m,int mat[][V])
{
    int ret = 0;
    for (int i=0;i<n;i++)
    {
        row[i] = 0;
        for (int j=0;j<m;j++)
            row[i] += mat[i][j];
    }
    /*
    for (int i=0;i<3;i++) permu[i] = i;
    for (int per=0;per<3*2;per++)
    {
        int sum = 0, i = 0, yes = 0;
        for (int t=0;t<3;t++)
        {
            sum = 0;
            for (;i<n;i++)
            {
                sum += row[i];
                if (sum == a[ permu[t] ])
                {
                    yes++;
                    i++;
                    break;
                }
            }
        }
        if (yes == 3 && i == n) ret++;
        next_permutation(permu, permu+3);
    }
    */
    for (int i=0;i<n;i++) sum[i] = (!i)? row[0] : sum[i-1] + row[i];
    
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n-1;j++)
        {
            b[0] = sum[i];
            b[1] = sum[j] - sum[i];
            b[2] = sum[n-1] - sum[j];
            sort(b, b+3);
            
            int yes = 0;
            for (int k=0;k<3;k++)
            if (b[k] == a[k])
                yes++;
                
            if (yes == 3) ret++;
        }
    //printf("ret is %d\n",ret);
    return ret;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&mat[i][j]);
            
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    sort(a, a+3);
    
    int ans = solve(n, m, mat);
    
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            c[j][i] = mat[i][j];
        
    ans += solve(m, n, c);
    
    printf("%d\n",ans);
}