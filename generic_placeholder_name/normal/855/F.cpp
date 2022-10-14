#include <iostream>

#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops, no-stack-protector")
#pragma GCC target ("avx,avx2,fma")

using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

constexpr int N=100001;

int a[N][2];
int l, r, x;
long long sum;

int32_t main() {
    fastio;
    unsigned short q; cin>>q; while(q--) {
        short t; cin>>t; if(t==1) {
            cin>>l>>r;
            cin>>x; short y=x>>31&1; x=abs(x);
            for(int i=l; i<r; i++) a[i][y]=!a[i][y]||a[i][y]>x?x:a[i][y];
        }
        else {
            cin>>l>>r;
            sum=0;
            for(int i=l; i<r; i++) sum+=a[i][0]&&a[i][1]?a[i][0]+a[i][1]:0;
            cout<<sum<<endl;
        }
    }
}