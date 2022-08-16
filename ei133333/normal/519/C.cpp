#include<bits/stdc++.h>
using namespace std;
 
template<typename T1, typename T2> istream& operator>>(istream& is, pair<T1,T2>& a){ return is >> a.first >> a.second; }
template<typename T1, typename T2> ostream& operator<<(ostream& os, pair<T1,T2>& a){ return os << a.first << " "<<a.second; }
template<typename T> istream& operator>>(istream& is, vector< T >& vc){ for(int i = 0; i < vc.size(); i++) is >> vc[i]; return is; }
template<typename T> ostream& operator<<(ostream& os, vector< T >& vc){ for(int i = 0; i < vc.size(); i++) os << vc[i] << endl; return os; }
 
#define ForEach(it,c) for(__typeof (c).begin() it = (c).begin(); it != (c).end(); it++)
#define ALL(v) (v).begin(), (v).end()
#define UNQ(s) { sort(ALL(s)); (s).erase( unique( ALL(s)), (s).end());}
#define fr first
#define sc second
 
typedef pair< int , int > Pi;
typedef pair< int , Pi > Pii;
 
typedef long long int64;
const int INF = 1 << 30;

int n, m;

int main(){
  cin >> n >> m;
  int ret = 0;
  for(int i = 0; i <= n / 2; i++){ // Ai
    int nokoriPuro = n - i * 2;
    int nokoriSyumi = m - i;
    if(nokoriSyumi < 0) break;
    ret = max( ret, i + min( nokoriPuro, nokoriSyumi / 2));
  }
  for(int i = 0; i <= n; i++){ // Ai
    int nokoriPuro = n - i;
    int nokoriSyumi = m - 2 * i;
    if(nokoriSyumi < 0) break;
    ret = max( ret, i + min( nokoriPuro / 2, nokoriSyumi));
  }
  cout << ret << endl;
}