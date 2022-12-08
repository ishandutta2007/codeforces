#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto &a:x)
using ll = long long;
using vi = vector<int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int h,g;
        cin>>h>>g;
        vector<int> a(1<<(h+1));
        vector<bool> locked(1<<h);
        rep(i,1,1<<h) cin>>a[i];
        function<void(int,int)> f = [&](int i, int d) {
            int left = 2*i, right = 2*i+1;
            if(a[left]==0 && a[right]==0) a[i] = 0;
            else {
                if(a[left]>a[right]) {
                    a[i] = a[left];
                    f(left, d+1);
                }
                else {
                    a[i] = a[right];
                    f(right,d+1);
                }
                if(d==g && a[left]==0 && a[right]==0) locked[i] = true;
                else if(a[left]>a[right]) locked[i] = locked[left];
                else locked[i] = locked[right];
            }
        };
        vector<int> ans;
        function<void(int,int)> f2 = [&](int i, int d) {
            if(a[i]==0) return;
            while(!locked[i]) {
                ans.push_back(i);
                f(i,d);
            }
            f2(2*i,d+1);
            f2(2*i+1,d+1);
        };
        f2(1,1);
        ll sum=0;
        rep(i,1,1<<g) sum += a[i];
        cout<<sum<<"\n";
        for(int x:ans) cout<<x<<" ";
        cout<<"\n";
    }
}