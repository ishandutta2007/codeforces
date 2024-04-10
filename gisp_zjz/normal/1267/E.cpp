#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int> pi;
int a[105][105],n,m,ans;
vector <int> s;
pi b[105];

int main(){
    cin >> n >> m;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin >> a[i][j];
    ans=m+1;
    for (int i=1;i<n;i++){
        for (int j=1;j<=m;j++) b[j]=(pi){a[j][i]-a[j][n],j};
        sort(b+1,b+m+1); reverse(b+1,b+m+1);
        int sum=0,pos=0;
        while (pos<m&&sum+b[pos+1].F>=0) pos++,sum+=b[pos].F;
        if (m-pos<ans){
            ans=m-pos; s.clear();
            for (int j=pos+1;j<=m;j++) s.pb(b[j].S);
        }
    }
    cout << ans << endl;
    for (auto x:s) cout << x << ' '; cout << endl;
    return 0;
}