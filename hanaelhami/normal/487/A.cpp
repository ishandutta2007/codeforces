#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define F first
#define S second
using namespace std;

const int MAXN = 101 * 1001 ;

int f (int x , int y)
{
    if(y<=0)
        return 1e18;
    if(x%y==0)
        return x/y ;
    return x/y+1;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int hp1 , atk1 , def1 , hp2 , atk2 , def2 , x , y , z ;
    cin >> hp1 >> atk1 >> def1 >> hp2 >> atk2 >> def2 >> x >> y >> z ;
    int ans = 1e18 ;
    for(int i = hp1 ; i <= 1000 ; i ++ )
    {
        for(int j = atk1 ; j <= 1000 ; j ++  )
        {
            if(j-def2<=0)
                continue ;
            for(int k = def1 ; k <= 1000 ; k ++ )
            {
                int pool = (i-hp1)*x + (j-atk1)*y + (k-def1)*z ;
                int q = f(hp2,(j-def2) ) ;
                int w = f(i,(atk2-k));
               // if(i==100&&j==atk1&&k==def1)
             //       cout << q << ' ' <<w<<endl;
                if(q<w)
                {
                 //   if(i==100&&j==atk1)
               //         cout << i << ' ' << j << ' '<<k<<endl;
                    ans=min(ans,pool);
                    break ;
                }

             //   cout << i << ' '<<j<<' '<<k << endl ;
            }
        }
    }
    cout << ans ;









}