#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

int n,m;
int a[501][501];
int c[501];
int x,y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            cin>>a[i][j];
        }
    }
    int r=-1;
    pii p={-1,-1};
    bool dist=0;
    for(int i=0; i<n;i++) {
        c[i] = 1;
        if(dist) {
            continue;
        }
        for(int j=1; j<m;j++) {
            if(a[i][j]!=a[i][j-1]) {
                p = {j-1,j};
                r=i;
                dist = 1;
            }
        }
    }
    int ans1=0,ans2=0;
    for(int i=0; i<n;i++) {
        if(i==r) {
            ans1^=a[i][p.ST];
            ans2^=a[i][p.ND];
        }
        else {
            ans1^=a[i][0];
            ans2^=a[i][0];
        }
    }
    if(ans1==0&&ans2==0) {
        cout<<"NIE";
        return 0;
    }
    cout<<"TAK\n";
    for(int i=0; i<n;i++) {
        if(i==r) {
            if(ans1!=0) {
                cout<<p.ST+1<<" ";
            }
            else {
                cout<<p.ND+1<<" ";
            }
        }
        else {
            cout<<"1 ";
        }
    }
}