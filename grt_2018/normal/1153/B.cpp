#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN = 100+1;
int n,m,h;
pair<pi,bool> a[2*MAXN];
bool c[MAXN][MAXN];
int w[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>h;
    for(int i=0; i<m;i++) {
        cin>>a[i].ST.ST;
        a[i].ST.ND=i;
    }
    for(int i=m; i<n+m;i++) {
        cin>>a[i].ST.ST;
        a[i].ST.ND=i-m;
        a[i].ND = 1;
    }
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) cin>>c[i][j];
    }
    sort(a,a+m+n);
    for(int i=0; i<m+n;i++) {
        if(a[i].ND==0) {
            for(int j=0; j<n;j++) {
                if(w[j][a[i].ST.ND]==0&&c[j][a[i].ST.ND]>0) {
                    w[j][a[i].ST.ND] = a[i].ST.ST;
                }
            }
        }
        else {
            for(int j=0; j<m;j++) {
                if(w[a[i].ST.ND][j]==0&&c[a[i].ST.ND][j]>0) {
                    w[a[i].ST.ND][j] = a[i].ST.ST;
                }
            }
        }
    }
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            cout<<w[i][j]<<" ";
        }
        cout<<"\n";
    }
}