#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define forn(i, n) for(int i=0; i<(n); i++)
#define pb push_back

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
    int n,k;
    cin >> n;
    cin >> k;
    vector<int> tasks;
    vector<bool> inter(n,false);
    vector<int> on(k);
    forn(i,n){
        int x;
        cin >> x;
        tasks.pb(x);
    }

    vector<pair<int,int> > w;
    int completed = 0;
    int nextTask = 0;
    forn(i,k){
        if(nextTask >= n){
            on[i] = -1;
        }else{
            w.pb(make_pair(0,tasks[nextTask]));
            on[i] = nextTask;
        }
        nextTask++;
    }

    while(completed < n){
        int percentage = ((int) ((100.0 *completed)/n +.5));
        //cout << completed << " " << percentage << endl;
        forn(i,k){
            if(on[i] >= 0){
                w[i].first++;
                if(w[i].first == percentage){
                    inter[on[i]] = true;
                }
                if(w[i].first == w[i].second){    //new task
                    completed++;
                    if(nextTask >= n){
                        on[i] = -1;
                    }else{
                        w[i] = make_pair(0,tasks[nextTask]);
                        on[i] = nextTask;
                    }
                    nextTask++;
                }
            }
        }
    }
    int total = 0;
    forn(i,n){
        if(inter[i]){
            total++;
        }
    }
    cout << total;
}