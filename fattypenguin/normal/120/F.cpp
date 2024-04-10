#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 107 , maxm = maxn*4;
      int n , test , tot , root , Tmax;
      int now[maxn] , pre[maxm] , y[maxm];
      bool use[maxn];
      
void cnt( int fir , int lst )
{
    pre[++tot] = now[fir] , now[fir] = tot , y[tot] = lst;
}

void init()
{
    tot = 0;
    memset( now , 0 , sizeof(now) );
    scanf( "%d" , &n );
    for ( int i = 1 ; i < n ; i++ )
    {
        int fir , lst;
        scanf( "%d %d" , &fir , &lst );
        cnt( fir , lst );
        cnt( lst , fir );
    }
}

void dfs( int x , int len )
{
    if ( len > Tmax ) Tmax = len , root = x;
    use[x] = false;
    for ( int mark = now[x] ; mark ; mark = pre[mark] )
        if ( use[y[mark]] ) dfs(y[mark],len+1);
}

int count()
{
    init();
    memset( use , true , sizeof(use) );
    Tmax = 0;
    dfs(1,0);
    memset( use , true , sizeof(use) );
    Tmax = 0;
    dfs(root,0);
    return Tmax;
}
int main()
{
    freopen( "input.txt" , "r" , stdin );
    freopen( "output.txt" , "w" , stdout );
    scanf( "%d" , &test );
    int res = 0;
    for ( int run = 1 ; run <= test ; run++ ) res += count();
    printf( "%d\n" , res );
    return 0;
}