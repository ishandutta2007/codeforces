#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 1001;
int n,m;
int a[MAXN][MAXN];
vector<int>cols[MAXN];
vector<int>rows[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            cin>>a[i][j];
            cols[j].PB(a[i][j]);
            rows[i].PB(a[i][j]);
        }
    }
    for(int i=0; i<n;i++) {
        sort(rows[i].begin(),rows[i].end());
        rows[i].resize(unique(rows[i].begin(),rows[i].end())-rows[i].begin());
    }
    for(int i=0; i<m;i++) {
        sort(cols[i].begin(),cols[i].end());
        cols[i].resize(unique(cols[i].begin(),cols[i].end())-cols[i].begin());
    }
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            int cm = lower_bound(cols[j].begin(),cols[j].end(),a[i][j])-cols[j].begin();
            int rm = lower_bound(rows[i].begin(),rows[i].end(),a[i][j])-rows[i].begin();
            int ch = cols[j].size()-cm-1;
            int rh = rows[i].size()-rm-1;
            cout<<max(cm,rm)+1+max(ch,rh)<<" ";
        }
        cout<<"\n";
    }
}