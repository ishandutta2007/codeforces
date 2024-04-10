#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN = 100;
int a[MAXN];
int n;
bool p;
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>a[i];
        if(a[i]&1) p = 1-p;
    }
    for(int i=0; i<n;i++) if(a[i]%2==p) ans++;
    cout<<ans;
}