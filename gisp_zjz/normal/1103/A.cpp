#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
typedef long long ll;
char s[maxn];
int p,q;
int main(){
    cin >> s;
    int n=strlen(s);
    for (int i=0;i<n;i++){
        if (s[i]=='0'){
            cout << 2 << ' ' << 1+p << endl;
            p=(p+1)%4;
        } else {
            cout << 1 << ' ' << 1+q*2 << endl;
            q=(q+1)%2;
        }
    }
}