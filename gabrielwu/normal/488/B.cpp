#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}


int main(){
    fast_io();
    int n;
    cin >> n;
    if(n==1){
      int a;
      cin >> a;
      cout << "YES\n" << a << "\n" <<3*a <<"\n"<<3*a<<endl;
    }else if(n==2){
      int a, b;
      cin >> a >> b;
      if(b<a) swap(a, b);
      for(int c = 1; c <= 1000000; c++){
        if((5*a + b + c) %3 == 0 && (5*a + b + c) /3 >= c && (c+b)==((5*a + b + c) /3-a)*2){
          cout << "YES" << "\n" << (5*a + b + c) /3 << endl << c << endl;
          return 0;
        }else if((a + b -3*c) %5 == 0 && -(a + b -3*c) /5 > 0 && -(a + b -3*c) /5 <= a && (a+b)==(c+(a + b -3*c) /5)*2){
          cout << "YES" << "\n" << -(a + b -3*c) /5 << endl << c << endl;

          return 0;
        }else{
          ll x = 4*(c-a)-a-b-c;
          if(x >= a && x <= c && (b+x)==(c-a)*2){
            cout << "YES\n" << x << endl << c << endl;
            return 0;
          }
        }
      }cout << "NO" << endl;
    }else if(n==3){
      int a, b, c;
      cin >> a >> b >> c;
      vi v;
      v.pb(a);
      v.pb(b);
      v.pb(c);
      sort(v.begin(), v.end());
      a = v[0];
      b = v[1];
      c = v[2];

      if((5*a + b + c) %3 == 0 && (5*a + b + c) /3 >= c && (c+b)==((5*a + b + c) /3-a)*2){
        cout << "YES" << "\n" << (5*a + b + c) /3 << endl;
      }else if((a + b -3*c) %5 == 0 && -(a + b -3*c) /5 > 0 && -(a + b -3*c) /5 <= a && (a+b)==(c+(a + b -3*c) /5)*2){
        cout << "YES" << "\n" << -(a + b -3*c) /5 << endl;
      }else{
        ll x = 4*(c-a)-a-b-c;
        if(x >= a && x <= c && (b+x)==(c-a)*2){
          cout << "YES\n" << x << endl;
        }else{
          cout << "NO" << endl;
        }
      }


    }else if(n==4){
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      vi v;
      v.pb(a);
      v.pb(b);
      v.pb(c);
      v.pb(d);
      sort(v.begin(), v.end());
      a = v[0];
      b = v[1];
      c = v[2];
      d = v[3];
      if(4*(d-a) == (a+b+c+d) && c+b==2*(d-a)){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }else{
      cout << "YES\n1\n1\n3\n3\n";
    }
}