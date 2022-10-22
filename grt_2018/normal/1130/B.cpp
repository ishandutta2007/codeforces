#include <bits/stdc++.h>

using namespace std;

#define ST first
#define ND second

const int MAXN = 1000*100+1;
int n;
int pos1,pos2;
vector<int>g[MAXN];
long long ans=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int a,i=0; i<2*n;i++) {
        cin>>a;
        g[a].push_back(i);
    }
    for(int i=1; i<=n;i++) {
        int op1 = abs(pos1-g[i][0]) + abs(pos2-g[i][1]);
        int op2 = abs(pos2-g[i][0]) + abs(pos1-g[i][1]);
        ans+=min(op1,op2);
        pos1 = g[i][0];
        pos2 = g[i][1];
    }
    cout<<ans;
    return 0;
}