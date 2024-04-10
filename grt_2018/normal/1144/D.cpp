#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1000*100+10;
int n,m,val;
int a[MAXN];
int cnt[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>a[i];
        cnt[a[i]]++;
        if(cnt[a[i]]>m) {
            m = cnt[a[i]];
            val = a[i];
        }
    }
    cout<<n - m<<"\n";
    for(int i=1; i<n;i++) {
        if(a[i-1]==val&&a[i]!=val) {
            if(val<a[i]) {
                cout<<"2 "<<i+1<<" "<<i<<"\n";
            }
            else {
                cout<<"1 "<<i+1<<" "<<i<<"\n";
            }
            a[i]=val;
        }
    }
    for(int i=n-2; i>=0;i--) {
        if(a[i+1]==val&&a[i]!=val) {
            if(val<a[i]) {
                cout<<"2 "<<i+1<<" "<<i+2<<"\n";
            }
            else {
                cout<<"1 "<<i+1<<" "<<i+2<<"\n";
            }
            a[i]=val;
        }
    }
    return 0;
}