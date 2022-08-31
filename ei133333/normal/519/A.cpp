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

int main(){
  vector< string > str(8);
  cin >> str;

  map< char, int > pt;
  pt['Q'] = 9, pt['R'] = 5, pt['B'] = 3, pt['N'] = 3, pt['P'] = 1;
  pt['q'] = -9, pt['r'] = -5, pt['b'] = -3, pt['n'] = -3, pt['p'] = -1;


  int ret = 0;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < str[i].size(); j++){
      ret += pt[str[i][j]];
    }
  }
  if(ret == 0) puts("Draw");
  else if(ret > 0) puts("White");
  else puts("Black");
}