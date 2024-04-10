/**
TASK:
USER: gabriel90
LANG: C++
**/
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define printVec(v) for(auto e: v){cout << e << " ";} cout << endl;
#define pb push_back
#define MOD 1000000007
#define f first
#define s second

typedef vector<int> vi;
typedef long long lint;

void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
int main(){
    fast_io();
    int n,q;
    cin >> n;
    vector<lint> v;
    forn(i,n){
        lint x;
        cin >> x;
        v.pb(x);
    }
    sort(v.begin(),v.end());
    vector<lint> d;
    vector<lint> dsum;
    forn(i,n-1){
        d.pb(v[i+1]-v[i]);
    }

    sort(d.begin(),d.end());
    lint acc = 0;
    forn(i,n-1){
        acc += d[i];
        dsum.pb(acc);
    }
    //printVec(d);
    //printVec(dsum);

    vector<lint> ans;
    cin >> q;
    forn(k,q){
        lint l,r;
        cin >> l >> r;
        lint wid = r-l+1;
        if(n==1){
            ans.pb(wid);
            continue;
        }
        int left = -1;
        int right = n-2;
        while(right-left > 1){
            int mid = (right+left)/2;
            if(d[mid]<wid){
                left = mid;
            }else{
                right = mid;
            }
        }
        lint sum;
        if(d[right] < wid){
            sum = dsum[right] + wid;
        }else{
            if(right == 0){
                sum = wid*n;
            }else{
                sum = dsum[right-1] + wid*(n-right);
            }

        }
        ans.pb(sum);

    }
    for(int i=0; i<q-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[q-1] << endl;
}