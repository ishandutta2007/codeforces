#include <bits/stdc++.h>

using namespace std;

#define X(x, y) (x-y+400)
#define Y(x, y) (x+y)

int N, M;
int U[1010][1010], D[1010][1010], L[1010][1010], R[1010][1010];
bool grid[1010][1010];
bool grid2[1010][1010];
int psum[1010][1010];
int psum2[1010][1010];
long long ans=0;

inline int get(int x1, int y1, int x2, int y2)
{
    if(x1>x2)
        swap(x1, x2);
    if(y1>y2)
        swap(y1, y2);
    x1--, y1--;
    return psum[x2][y2]-psum[x1][y2]-psum[x2][y1]+psum[x1][y1];
}

inline int _get2(int x1, int y1, int x2, int y2)
{
    if(x1>x2)
        swap(x1, x2);
    if(y1>y2)
        swap(y1, y2);
    x1--, y1--;
    return psum2[x2][y2]-psum2[x1][y2]-psum2[x2][y1]+psum2[x1][y1];
}

inline int get2(int x1, int y1, int x2, int y2)
{
    return _get2(X(x1, y1), Y(x1, y1), X(x2, y2), Y(x2, y2));
}

void solve()
{
    memset(U, 0, sizeof U);
    memset(D, 0, sizeof D);
    memset(L, 0, sizeof L);
    memset(R, 0, sizeof R);
    memset(psum, 0, sizeof psum);
    memset(psum2, 0, sizeof psum2);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
    {
        getchar();
        for(int j=1; j<=M; j++)
            grid2[X(i, j)][Y(i, j)]=grid[i][j]=getchar()-'0';
    }
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
        {
            if(grid[i][j])
            {
                U[i][j]=0;
                L[i][j]=0;
            }
            else
            {
                U[i][j]=U[i-1][j]+1;
                L[i][j]=L[i][j-1]+1;
            }
        }
    for(int i=N; i>=1; i--)
        for(int j=M; j>=1; j--)
        {
            if(grid[i][j])
            {
                D[i][j]=0;
                R[i][j]=0;
            }
            else
            {
                D[i][j]=D[i+1][j]+1;
                R[i][j]=R[i][j+1]+1;
            }
        }
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+grid[i][j];
    for(int i=1; i<=1000; i++)
        for(int j=1; j<=1000; j++)
            psum2[i][j]=psum2[i-1][j]+psum2[i][j-1]-psum2[i-1][j-1]+grid2[i][j];
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            if(!grid[i][j])
            {
                int len=min(L[i][j], U[i][j]);
                for(int k=1; k<len; k++)
                    ans+=get2(i-k, j, i, j-k)==0;
                len=min(R[i][j], U[i][j]);
                for(int k=1; k<len; k++)
                    ans+=get2(i-k, j, i, j+k)==0;
                len=min(L[i][j], D[i][j]);
                for(int k=1; k<len; k++)
                    ans+=get2(i+k, j, i, j-k)==0;
                len=min(R[i][j], D[i][j]);
                for(int k=1; k<len; k++)
                    ans+=get2(i+k, j, i, j+k)==0;
                for(int k=1; k<=N-i; k++)
                {
                    if(j-k<1 || j+k>M || get2(i, j, i+k, j-k) || get2(i, j, i+k, j+k))
                        break;
                    ans+=get(i+k, j-k, i+k, j+k)==0;
                }
                for(int k=1; k<i; k++)
                {
                    if(j-k<1 || j+k>M || get2(i, j, i-k, j-k) || get2(i, j, i-k, j+k))
                        break;
                    ans+=get(i-k, j-k, i-k, j+k)==0;
                }
                for(int k=1; k<=M-j; k++)
                {
                    if(i-k<1 || i+k>N || get2(i, j, i-k, j+k) || get2(i, j, i+k, j+k))
                        break;
                    ans+=get(i-k, j+k, i+k, j+k)==0;
                }
                for(int k=1; k<j; k++)
                {
                    if(i-k<1 || i+k>N || get2(i, j, i-k, j-k) || get2(i, j, i+k, j-k))
                        break;
                    ans+=get(i-k, j-k, i+k, j-k)==0;
                }
            }
    printf("%lld\n", ans);
    return 0;
}