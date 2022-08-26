#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int M=1000000007;
const int maxn=1000006;
int n,k,a[maxn];
void mp(int x,int y){a[x]=y;a[y]=x;}
int main(){
    int _;
    cin >> _;
    while (_--){
        cin >> n >> k;
        for (int i=0;i<n;i++) a[i]=n-1-i;
        if (n==4&&k==3){puts("-1");continue;}
        if (n==k+1){
            mp(0,1);
            mp(2,n-2);
            mp(n-3,n-1);
        } else {
            mp(k,n-1);
            mp(0,n-1-k);
        }
        for (int i=0;i<n;i++) if (i<a[i]) printf("%d %d\n",i,a[i]);
    }
    return 0;
}