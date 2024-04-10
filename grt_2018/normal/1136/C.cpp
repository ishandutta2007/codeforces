#include <bits/stdc++.h>

using namespace std;

const int MAXN = 501;
int n,m;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
vector<int>v1,v2;
bool visited[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) cin>>a[i][j];
    }
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) cin>>b[i][j];
    }
    int k=max(n,m);
    for(int i=0; i<n;i++) {
        v1.push_back(a[i][0]);
        v2.push_back(b[i][0]);
        visited[i][0]=1;
        for(int j=i-1; j>=0; j--) {
            if(i-j>=m) break;
            visited[j][i-j] = 1;
            v1.push_back(a[j][i-j]);
            v2.push_back(b[j][i-j]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1!=v2) {
            cout<<"NO";
            return 0;
        }
        v1.clear();
        v2.clear();
    }
    for(int i=0; i<m; i++) {
        for(int j=n-1; j>=0;j--) {
            if(i+(n-1-j)>=m) break;
            v1.push_back(a[j][i+(n-1-j)]);
            v2.push_back(b[j][i+(n-1-j)]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1!=v2) {
            cout<<"NO";
            return 0;
        }
        v1.clear();
        v2.clear();
    }
    cout<<"YES";
    return 0;
}