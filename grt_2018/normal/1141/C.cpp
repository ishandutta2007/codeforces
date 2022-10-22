#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1000*100+1;
int q[MAXN],n;
long long s1,s2,act;
long long p[MAXN];
bool visited[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n;i++) {
        cin>>q[i];
        act+=q[i];
    }
    for(int i=n-1; i>=1; i--) {
        s1+=act;
        act-=q[i];
    }
    s2=(long long)n*(n+1)/2;
    p[1] = (s2-s1)/n;
    if(p[1]<1||p[1]>n) {
        cout<<"-1";
        return 0;
    }
    visited[p[1]]=1;
    for(int i=2; i<=n;i++) {
        p[i] = p[i-1]+q[i-1];
        if(p[i]<1||p[i]>n||visited[p[i]]) {
            cout<<"-1";
            return 0;
        }
        visited[p[i]]=1;
    }
    for(int i=1; i<=n;i++) cout<<p[i]<<" ";
    return 0;
}