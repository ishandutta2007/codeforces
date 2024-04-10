#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int a[55][55],n,m,_;
int main(){
    cin >> _;
    while (_--){
        cin >> n >> m;
        memset(a,0,sizeof(a));
        a[1][1]=a[n][1]=a[n][m]=a[1][m]=1;
        for (int i=3;i+2<=n;i+=2) a[i][1]=a[i][m]=1;
        for (int i=3;i+2<=m;i+=2) a[1][i]=a[n][i]=1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++) printf("%d",a[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}