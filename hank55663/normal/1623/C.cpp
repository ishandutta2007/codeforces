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
#define index Index
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    int h[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&h[i]);
    }
    int Max=1e9+1,Min=1;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        LL a[200005];
        for(int i = 0;i<n;i++)a[i]=h[i];
        int ok=1;
        for(int i = n-1;i>=2;i--){
            int add=min(h[i]/3ll,(a[i]-mid)/3);
            a[i-1]+=add;
            a[i-2]+=add*2;
            if(a[i]<mid){
                ok=0;
            }
        }
        if(a[0]>=mid&&a[1]>=mid&&ok)Min=mid;
        else Max=mid;
    }
    printf("%d\n",Min);
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