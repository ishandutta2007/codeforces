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

int P[2000007];

// Transform S into new string with special characters inserted.
string convertToNewString(const string &s) {
    string newString = "@";

    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

void solve(const string &s, int edges, int ssize) {

    string Q = convertToNewString(s);
    forn(i,Q.size()+2){
        P[i] = 0;
    }
    int c = 0, r = 0;                // current center, right limit

    for (int i = 1; i < Q.size() - 1; i++) {
        // find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);

        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r) {
            c = i;              // next center = i
            r = i + P[i];
        }
    }

    // Find the longest palindrome length in p.
    int besteu, ci = 0;
    int ans = 0;

    for (int i = 2; i < Q.size() - 2; i++) {
        int len;
        if(i%2 == 0){
            int truei = i/2-1;
            if(min(truei-P[i]/2, ssize-1-(truei+P[i]/2)) > edges){
                continue;
            }
            int eu = min(edges, min(truei-P[i]/2, ssize-1-(truei+P[i]/2)));
            len = P[i] + 2*eu;
            if(len > ans){
                besteu = eu;
                ans = len;
                ci = i;
            }
        }else{
            int truei = i/2-1;  //Left of center
            if(min(truei+1-P[i]/2, ssize-1-(truei+P[i]/2)) > edges){
                continue;
            }
            int eu = min(edges,min(truei+1-P[i]/2, ssize-1-(truei+P[i]/2)));
            len = P[i] + 2*eu;
            if(len > ans){
                besteu = eu;
                ans = len;
                ci = i;
            }
        }
    }
    //cout << besteu << " " << ci << " " << ans << endl;
    //printArr(P, Q.size());

    cout << s.substr(0,besteu) << s.substr( (ci - 1 - P[ci]) / 2, P[ci]) << s.substr(ssize-besteu, besteu) << "\n";
    /*
    printArr(P, Q.size());
    cout << maxPalindrome << "\n";
    cout << "p: " << s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome) << "\n";

    return maxPalindrome;*/
}

int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
        string s;
        cin >> s;
        int ssize = (int) s.size();
        int edges = 0;
        //cout << "S: " << s << " " << s.size() << (edges < ((int)s.size())/2 - 1) << endl;

        while((edges < ssize/2 - 1) && s.at(edges)==s.at(ssize-1-edges)){
            edges++;
        }
        //cout << "edges" << edges << endl;
        solve(s, edges, ssize);
    }
    /*
    while(1){
        string s;
        cin >> s;
        cout << longestPalindromeSubstring(s);
        cout << "FLUSH" << endl;

    }*/

}