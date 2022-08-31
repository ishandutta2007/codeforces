#include<bits/stdc++.h>
#define maxn 234560

using namespace std;
typedef long long ll;
ll n,s,a[maxn],b[maxn];

int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        scanf("%I64d%I64d",&a[i],&b[i]);
    }
    sort(a,a+n); sort(b,b+n);
    for (int i=0;i<n;i++) s+=max(a[i],b[i]);
    cout << s+n << endl;
}