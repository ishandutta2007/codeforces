#include<bits/stdc++.h>
#define maxn 123456

using namespace std;
typedef long long ll;
int n,m,p,q;

int main(){
    cin >> n >> m;
    for (int i=0;i<m;i++) cin >> p >> q;
    for (int i=0;i<n;i++) cout << i%2;
    cout << endl;
}