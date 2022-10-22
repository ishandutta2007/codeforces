#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int>pi;
typedef vector<int>vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 501;
int n,m;
bool A[MAXN][MAXN],B[MAXN][MAXN];
int col[MAXN];
int row[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n;i++) for(int j=0; j<m;j++) cin>>A[i][j];
    for(int i=0; i<n;i++) for(int j=0; j<m;j++) cin>>B[i][j];
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            if(A[i][j]!=B[i][j]) {
                col[j]++;
                row[i]++;
            }
        }
    }
    for(int i=0; i<n;i++) if(row[i]%2==1) {
        cout<<"No";
        return 0;
    }
    for(int i=0; i<m;i++) if(col[i]%2==1) {
        cout<<"No";
        return 0;
    }
    cout<<"Yes";
}