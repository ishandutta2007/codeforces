#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct pt{
    int r,s;
};

bool vis[25][400];

bool blocked_hori[25][400],blocked_straight[25][400];

queue<pt> q;

void add(int r,int s){
    if (vis[r][s]) return;
    q.push((pt){r,s});
    vis[r][s] = true;
}

inline int nxt(int s){
    if (s == 359) return 0;
    return s+1;
}

inline int prev(int s){
    if (s == 0) return 359;
    return s-1;
}

void solve(){
    int n;
    cin >> n;
    memset(blocked_hori,false,sizeof blocked_hori);
    memset(blocked_straight,false,sizeof blocked_straight);
    memset(vis,false,sizeof vis);
    for (int i = 1;i <= n;i++){
        string type;
        cin >> type;
        if (type == "C"){
          int r,s1,s2;
          cin >> r >> s1 >> s2;
          if (s1 < s2){
              for (int i = s1;i < s2;i++) blocked_hori[r][i] = true;
          }
          else{
              for (int i = s1;i < 360;i++) blocked_hori[r][i] = true;
              for (int i = 0;i < s2;i++) blocked_hori[r][i] = true;
          }
        }
        else{
            int r1,r2,s;
            cin >> r1 >> r2 >> s;
            for (int i = r1+1;i <= r2;i++) blocked_straight[i][s] = true;
        }
    }
    while (!q.empty()) q.pop();
    for (int i = 0;i < 360;i++){
        add(1,i);
    }
    bool tf = false;
    while (!q.empty()){
        pt u = q.front();
        q.pop();
        if (blocked_hori[u.r][u.s] == false){
            add(u.r+1,u.s);
            if (u.r == 20){
                tf = true;
                break;
            }
        }
        if (u.r != 1 && blocked_hori[u.r-1][u.s] ==false){
            add(u.r-1,u.s);
        }
        if (blocked_straight[u.r][nxt(u.s)] == false){
            add(u.r,nxt(u.s));
        }
        if (blocked_straight[u.r][u.s] == false){
            add(u.r,prev(u.s));
        }
    }
    if (tf){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}