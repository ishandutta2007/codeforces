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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[200005];
    scanf("%s",c);
    for(int i = 0;i<n;i++){
        if(k&1){
            if(c[i]=='0')c[i]='1';
            else c[i]='0';
        }
    }
    vector<int> ans;
        int cnt[200005];
    fill(cnt,cnt+n+1,0);
    for(int i=0;i<n;i++){
        if(c[i]=='0'&&k){
            k--;
            c[i]='1';
            cnt[i]++;
            //ans.push_back(i);
        }
    }

    //for(int i = 0;i<k;i++)ans.pb(n-1);
        cnt[n-1]+=k;
    k%=2;

    if(k)c[n-1]='0';
    printf("%s\n",c);
   
    for(auto it:ans)cnt[it]++;//printf("%d ",it);
    for(int i = 0;i<n;i++)printf("%d ",cnt[i]);
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
UKOKCUEUKCKPNKPKPDEUFUFJUFBFPDPBFIFP
*/