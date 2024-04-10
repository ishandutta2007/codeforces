/**
TASK:
USER: gabriel90
LANG: C++
**/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define forn(i, n) for(int i=0; i<n; i++)

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

bool p[50][50];
int sets[50][50];
int n;
vector<pair<int,int> > a;
vector<pair<int,int> > b;

int dfs(int i,int j,int id){
    sets[i][j] = id;
    if(id==1){
        a.push_back(make_pair(i,j));
        //cout << "A" << i << " " << j << endl;
    }else{
        b.push_back(make_pair(i,j));
        //cout << "B" << i << " " << j << endl;
    }
    if(i>0){
        if(sets[i-1][j]!=id && p[i-1][j]){
            dfs(i-1,j,id);
        }
    }
    if(i<n-1){
        if(sets[i+1][j]!=id && p[i+1][j]){
            dfs(i+1,j,id);
        }
    }
    if(j>0){
        if(sets[i][j-1]!=id && p[i][j-1]){
            dfs(i,j-1,id);
        }
    }
    if(j<n-1){
        if(sets[i][j+1]!=id && p[i][j+1]){
            dfs(i,j+1,id);
        }
    }
}
int dist(pair<int,int> f,pair<int,int> s){
    int x1 = f.first;
    int y1 = f.second;
    int x2 = s.first;
    int y2 = s.second;
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){
    fast_io();
    cin >> n;
    int r1,r2,c1,c2;
    cin >> r1;
    cin >> c1;
    cin >> r2;
    cin >> c2;
    forn(i,n){
        string x;
        cin >> x;
        forn(j,n){
            if(x.at(j)=='0'){
                p[i][j] = true;
            }else{
                p[i][j] = false;
            }
            sets[i][j] = -1;
        }
    }

    dfs(r1-1,c1-1,1);
    dfs(r2-1,c2-1,2);

    int ans = 50*50*2;
    forn(i,a.size()){
        forn(j,b.size()){
            ans = min(ans,dist(a[i],b[j]));
        }
    }
    cout << ans;

}