#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1000*100+10;
int n;
string s,t;
int a[MAXN];
int b[MAXN];
int c[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>s>>t;
    for(int i=0; i<n;i++) {
        a[i] = s[i] - 'a'+1;
        b[i] = t[i] - 'a'+1;
    }
    for(int i=n-1; i>=0; i--) {
        c[i] += b[i]+a[i];
        //if(c[i]>26) {
        //    c[i]-=26;
        //    c[i-1]++;
        //}
    }
    for(int i=0; i<n;i++) {
        b[i] = c[i]/2;
        if(c[i]&1) c[i+1]+=26;
    }
    for(int i=n-1; i>=0;i--) {
        if(b[i]>26) {
            b[i]-=26;
            b[i-1]++;
        }
    }
    for(int i=0; i<n;i++) cout<<char(b[i]+'a'-1);
    return 0;
}