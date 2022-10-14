#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i=0; i<n; i++)

void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void io(string taskname){
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
    vector<bool> dir;
    vector<int> hop;

    cin >> n;
    bool visited[n] = {false};
    forn(i,n){
        char c;
        cin >> c;
        if(c=='>'){
            dir.push_back(true);
        }else{
            dir.push_back(false);
        }
    }
    forn(i,n){
        int length;
        cin >> length;
        if(dir.at(i)){
            hop.push_back(length);
        }else{
            hop.push_back(-length);
        }
    }
    int atrn = 0;
    int atnext;
    bool finite = false;
    forn(i,n){
        atnext = atrn + hop[atrn];
        if(atnext >= 0 && atnext < n){
            atrn = atnext;
        }else{
            finite = true;
            break;
        }
    }
    if(finite){
        cout << "FINITE";
    }else{
        cout << "INFINITE";
    }


}