#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
string s[22345],t[22345];
int n,m,q,x;

int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> s[i];
    for (int i=0;i<m;i++) cin >> t[i];
    cin >> q;
    while (q--){
        cin >> x; x--;
        cout << s[x%n] << t[x%m] << endl;
    }
    return 0;
}