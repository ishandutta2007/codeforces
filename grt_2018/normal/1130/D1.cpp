#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5001;
const int INF = 1000*1000*1000;
int n,m;
vector<int>cand[MAXN];
int cnt[MAXN];
int c[MAXN];
int minux;

int dist(int a, int b) {
    if(b>=a) return b-a;
    else return n-(a-b);
}

pair<int,int> Q[2*MAXN];
int pocz,kon;

void wstaw(int w,int id) {
    while(kon-1>=pocz&&Q[kon-1].first<w) {
        kon--;
    }
    Q[kon] = {w,id};
    kon++;
}

void usun(int id) {
    if(Q[pocz].second==id) pocz++;
}

int get_max() {
    return Q[pocz].first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int a,b,i=0; i<m;i++) {
        cin>>a>>b;
        cand[a].push_back(b);
    }
    for(int i=1; i<=n;i++) {
        int d = INF, nr=i;
        cnt[i] = cand[i].size();
        if(cnt[i]>0) {
            for(auto it:cand[i]) {
                if(d>dist(i,it)) {
                    d = dist(i,it);
                    nr = it;
                }
            }
            c[i] = nr;
        }
    }
    for(int i=1; i<=n;i++) {
        if(cnt[i]) wstaw(dist(1,i)+(cnt[i]-1)*n+dist(i,c[i]),i);
    }
    cout<<get_max()<<" ";
    for(int i=2; i<=n;i++) {
        usun(i-1);
        minux++;
        if(cnt[i-1]) wstaw(dist(i,i-1)+(cnt[i-1]-1)*n+dist(i-1,c[i-1])+minux,
                           i-1);
        cout<<get_max() - minux<<" ";
    }
    return 0;
}