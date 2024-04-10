#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define printVec(v) for(auto e: v){cout << e << " ";} cout << endl;
#define pb push_back
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
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<int> vi;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << ""; for(int i = 0; i < v.size(); i++) {if (i) cout << " "; cout << v[i];} return cout << endl;
}

int main(){
    int n;
    cin >> n;
    if(n%2==0){
        cout << "NO" << endl;
    }else if(n==1){
        cout << "YES" << endl;
        cout << "1 2" << endl;
    }else{
        int i = 0;
        int num = 1;
        vi v(2*n);
        while(num<= 2*n){
            v[i] = num;
            num++;
            if(num >2*n){break;}
            v[i+n] = num;
            i++;
            num++;
            if(num >2*n){break;}
            v[i+n] = num;
            num++;
            if(num >2*n){break;}
            v[i] = num;
            i++;
            num++;
            if(num >2*n){break;}
        }
        cout << "YES" << endl;
        cout << v;
    }
}