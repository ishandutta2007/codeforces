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
  int N;
  cin >> N;
  multiset< int > A, B, C, D;
  for(int i = 0; i < N; i++){
    int digit;
    cin >> digit;
    A.insert(digit);
  }
  for(int i = 0; i < N - 1; i++){
    int digit;
    cin >> digit;
    B.insert(digit);
    D.insert(digit);
  }
  for(int i = 0; i < N - 2; i++){
    int digit;
    cin >> digit;
    C.insert(digit);
  }

  int digit = 0;
  ForEach(i, A){
    multiset< int >::iterator it = B.find(*i);
    if(it == B.end()){
      digit = *i;
      break;
    } else {
      B.erase(it);
    }
  }

  int digit2;
  ForEach(i, D){
    multiset< int >::iterator it = C.find(*i);
    if(it == C.end()){
      digit2 = *i;
      break;
    } else {
      C.erase(it);
    }
  }
  cout << digit << endl;
  cout << digit2 << endl;
}