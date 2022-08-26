#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int p,q,n,r;
char s[maxn];
int main(){
    int T;cin >> T;
    while (T--){
        cin >> n >> s;
        r=0; p=0; while (r<n&&s[r]=='<') r++,p++;
        r=n-1; q=0; while (r>=0&&s[r]=='>') r--,q++;
        cout << min(p,q) << endl;
    }
}