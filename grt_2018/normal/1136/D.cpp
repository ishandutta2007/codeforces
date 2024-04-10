#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3*1000*100+1;
int n,m,s;
bool stone[MAXN];
int p[MAXN];
vector<int>V[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n;i++) cin>>p[i];
    for(int a,b,i=0; i<m;i++) {
        cin>>a>>b;
        V[a].push_back(b);
    }
    for(int i=n-2; i>=0;i--) {
        int ile=0;
        bool used=0;
        for(auto it:V[p[i]]) {
            if(stone[it]) ile++;
            if(it==p[n-1]) used=1;
        }
        if((ile!=s)||(!used)) {
            s++;
            stone[p[i]]=1;
        }
    }
    cout<<n-1-s;
    return 0;
}