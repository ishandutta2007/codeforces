#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int l=0,r=n-1;
    vector<int> v;
    while(l<=r){
        if(a[l]!=a[r]){
            v.pb(a[l]);
            v.pb(a[r]);
            break;
        }
        l++;
        r--;
    }
    if(l>r){
        printf("YES\n");
    }
    else{
        for(auto it:v){
            int ok=1;
            int l=0,r=n-1;
             while(l<=r){
                if(a[l]==it){
                    l++;
                    continue;
                }
                if(a[r]==it){
                    r--;
                    continue;
                }
                if(a[l]!=a[r]){
                    ok=0;
                    break;
                }
                l++;
                r--;
            }
            if(ok){
                printf("YES\n");
                return;
            }
        }
        printf("NO\n");
    }
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/