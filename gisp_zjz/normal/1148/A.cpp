#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=3e5+3;
int n;
ll a,b,c;
int main(){
    cin >> a >> b >> c;
    a+=c; b+=c;
    if (a==b) cout << a+b << endl;
    else if (a>b) cout << b*2+1 << endl;
    else cout << a*2+1 << endl;
    return 0;
}