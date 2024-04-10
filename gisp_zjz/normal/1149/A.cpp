#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=500050;
int n,c1,c2,k,o;
int main(){
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> k;
        if (k==1) c1++; else c2++;
    }
    if (c2>0){
        cout << "2 "; c2--;
    }
    if (c1%2==0&&c1>0){
        o=1; c1--;
    }
    for (int i=0;i<c1;i++) cout << "1 ";
    for (int i=0;i<c2;i++) cout << "2 ";
    if (o) cout << "1 ";
    cout << endl;
    return 0;
}