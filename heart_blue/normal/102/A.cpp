#include <iostream>
using namespace std;

const int N = 110;
int a[N][N];
int b[N];

int main()
{
    int n,m;
    cin >> n >> m;
    memset(a,0,sizeof(a));
    for(int i = 1; i <= n; i++) cin >> b[i];
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        a[x][y] = a[y][x] =1;
    }
    int ans = 1<<30;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(!a[i][j]) continue;
            for(int k = j+1; k <= n; k++)
            {
                if(a[i][k] && a[k][j]) ans = ans<b[i]+b[j]+b[k]?ans:b[i]+b[j]+b[k];
            }
        }
    }
    if(ans == 1<<30) ans = -1;
    cout << ans << endl;
    return 0;
}