#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

int n,a[101];
int b,s=200;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>a[i];
        s=min(s,a[i]);
        b=max(b,a[i]);
    }
    int sr,D;
    if((b-s)%2==1) {
        sr = b;
        D = b-s;
    }
    else {
        sr = (b+s)/2;
        D = sr-s;
    }
    for(int i=0; i<n;i++) {
        if(a[i]!=s&&a[i]!=b&&a[i]!=sr) {
            cout<<"-1";
            return 0;
        }
    }
    cout<<D;
}