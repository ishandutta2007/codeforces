#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int>pi;
typedef vector<int>vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 1000+1;
const int INF = 1000*1000*1000;
pi w[MAXN];
int ans,n,h;

bool checkq(int x) {
    int ind = 0,s=0;
    for(int i=n-1; i>=0;i--) {
        if(w[i].ND<=x) {
            if(ind%2==0) s+=w[i].ST;
            if(s>h) return 0;
            ind++;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>h;
    for(int i=0; i<n;i++) {
        cin>>w[i].ST;
        w[i].ND = i+1;
    }
    sort(w,w+n);
    int pocz = 0, kon = n,sr;
    while(pocz<=kon) {
        sr=(pocz+kon)/2;
        if(checkq(sr)) pocz=sr+1;
        else kon=sr-1;
    }
    cout<<pocz-1;
}