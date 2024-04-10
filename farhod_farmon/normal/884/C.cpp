#include <bits/stdc++.h>
#define in freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
using namespace std;
vector< int >v[100005] , v1;
int used[100005] , kol;
void dfs( int pos ){
    used[pos] ++;
    kol ++;
    for( int k = 0; k < v[pos].size(); k ++ ){
        if( used[v[pos][k]] == 0 ){
            dfs( v[pos][k] );
        }

    }
}
int main()
{
//   in;
//   out;
   int a , b[100005] , i , j;
   cin >> a;
   for( i = 1; i <= a; i ++ ){
      cin >> b[i];
      v[b[i]].push_back( i );
      v[i].push_back( b[i] );
   }
   for( i = 1; i <= a; i ++ ){
      if( used[i] == 0 ){
         dfs(i);
         v1.push_back( kol );
         kol = 0;
      }
   }
   long long int maxn = 0 , maxn2 = 0 , ind1 = 0 , ind2 = 0;
   for( i = 0; i < v1.size(); i ++ ){
     if( maxn < v1[i] ){
        maxn = v1[i];
        ind1 = i;
     }
   }
   v1[ind1] = 0;
   for( i = 0; i < v1.size(); i ++ ){
     if( maxn2 < v1[i] ){
        maxn2 = v1[i];
        ind2 = i;
     }
   }
   v1[ind2] = 0;
   long long ans = 0;
   ans = (maxn + maxn2) * (maxn + maxn2);
   for( i = 0; i < v1.size(); i ++ ){
      ans += ( v1[i] * v1[i] * 1ll );
   }
   cout << ans << endl;
}