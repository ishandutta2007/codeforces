#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int n,_,ans,a[105],b[105];
bool check(int x,int y,int z){
    return (x-z)*(a[x]-a[y])==(x-y)*(a[x]-a[z]);
}
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        if (n<=2){puts("0");continue;}
        ans=n-2;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++){
                int cnt=0;
                for (int k=0;k<n;k++) if (check(i,j,k)) ++cnt;
                ans=min(ans,n-cnt);
            }
        printf("%d\n",ans);
    }
}