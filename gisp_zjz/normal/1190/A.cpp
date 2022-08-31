#include<bits/stdc++.h>
#define maxn 500050
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
ll n,m,k,p,a[maxn],v;
int ans;

int main(){
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++) cin >> a[i];
    int j=1; ans=0; v=0;
    while (j<=m){
        p=((a[j]-v-1)/k+1)*k;
        while (a[j]-v<=p) j++;
        v=j-1; ans++;
    }
    cout << ans << endl;
}