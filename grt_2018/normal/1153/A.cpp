#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN = 100*1000+1;
int n,t;
int ans = 1000*1000*1000;
int bus;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    for(int a,b,i=0; i<n;i++) {
        cin>>a>>b;
        int x = ((t-a-1)/b+1)*b+a;
        if(t<=a) x = a;
        if(ans>x) {
            ans = x;
            bus = i+1;
        }
    }
    cout<<bus;
}