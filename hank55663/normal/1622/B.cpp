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
const int mod=1e9+7;
void solve(){
    int n;
    scanf("%d",&n);
    int p[200005];
    char c[200005];
    for(int i = 0;i<n;i++)scanf("%d",&p[i]);
    scanf("%s",c);
    int tot=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='0')tot++;
    }
    set<int> s;
    for(int i = 1;i<=n;i++){
        s.insert(i);
    }
    int ans[200005];
    MEM(ans);
    for(int i = 0;i<n;i++){
        if(c[i]=='0'){
            if(p[i]<=tot){
                ans[i]=p[i];
                s.erase(p[i]);
            }
        }
        else{
            if(p[i]>tot){
                ans[i]=p[i];
                s.erase(p[i]);
            }
        }
    }
    for(int i = 0;i<n;i++){
        if(ans[i]==0){
            if(c[i]=='0'){
                ans[i]=*s.begin();
                s.erase(s.begin());
            }
            else{
                ans[i]=*s.rbegin();
                s.erase(*s.rbegin());
            }
        }
    }
    for(int i = 0;i<n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
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