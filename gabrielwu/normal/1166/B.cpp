/**
TASK:
USER: gabriel90
LANG: C++
**/
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define printVec(v) for(auto e: v){cout << e << " ";} cout << endl;
#define pb push_back
#define MOD 1000000007
#define f first
#define s second

typedef vector<int> vi;
typedef long long lint;

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
    int k;
    cin >> k;
    int i = 0;
    for(; i<1000; i++){
        if(i>4 && k%i==0 && k/i > 4){
            break;
        }
    }
    if(i==1000){
        cout << -1 << endl;
    }else{
        vector<char> vowels;
        vowels.pb('a');vowels.pb('e');vowels.pb('i');vowels.pb('o');vowels.pb('u');
        int in = 0;
        forn(a,i){
            int ind = in;
            forn(b, k/i){
                cout << vowels[ind%5];
                ind++;
            }
            in++;
        }
    }
}