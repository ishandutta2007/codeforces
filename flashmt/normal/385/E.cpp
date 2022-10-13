#include <bits/stdc++.h>
using namespace std;
const int M0[6][6] = {{2, 1, 1, 0, 1, 2}, {1, 2, 0, 1, 1, 2}, {1, 1, 1, 0, 1, 2},
                  {1, 1, 0, 1, 1, 2}, {0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 1}};
const int SZ = 6;

long long n;

struct matrix
{
    long long a[SZ][SZ];
    
    matrix() 
    {
        memset(a, 0, sizeof a);
    }
    
    matrix operator * (matrix u)
    {
        matrix res;
        
        for (int i = 0; i < SZ; i++)
            for (int j = 0; j < SZ; j++)
                for (int k = 0; k < SZ; k++)
                {
                    res.a[i][j] += a[i][k] * u.a[k][j];
                    res.a[i][j] %= n;
                }
                
        return res;
    }
} m[66];

int main()
{
    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++)
            m[0].a[i][j] = M0[i][j];
            
    long long sx, sy, dx, dy, t;
    cin >> n >> sx >> sy >> dx >> dy >> t;
    sx--; sy--;
    dx = (dx + n * 1000) % n;
    dy = (dy + n * 1000) % n;
    
    matrix ans;
    ans.a[0][0] = sx; ans.a[1][0] = sy;
    ans.a[2][0] = dx; ans.a[3][0] = dy;
    ans.a[4][0] = 0;  ans.a[5][0] = 1;
    
    for (int i = 0; i < 60; i++) m[i + 1] = m[i] * m[i];
    
    for (int i = 60; i >= 0; i--)
        if (t >= 1LL << i)
        {
            ans = m[i] * ans;
            t ^= 1LL << i;
        }
        
    cout << ans.a[0][0] + 1 << ' ' << ans.a[1][0] + 1 << endl;
}