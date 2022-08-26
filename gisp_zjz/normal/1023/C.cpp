#include<bits/stdc++.h>
#define maxn 234005
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
char s[maxn],t[maxn];
int n,m,p,q,f,pos;

int main(){
    cin >> n >> m; cin >> s;
    p=q=m/2;
    for (int i=0;i<n;i++) {
        if (s[i]=='('){
            if (p) printf("("),p--;
        }
        else {
            if (q) printf(")"),q--;
        }
    }
    puts("");
}