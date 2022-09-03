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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[2005];
    int sum=0;
    map<int,int> m;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sum^=a[i];
        m[sum]++;
    }
    if(sum==0){
        printf("YES\n");
    }
    else{
        int ok1=0,ok2=0;
        int tmp=0;
        for(int i = 0;i<n;i++){
            tmp^=a[i];
            if(tmp==sum)ok1=1;
            if(tmp==0&&ok1)ok2=1;
        }
        if(ok2)printf("YES\n");
        else printf("NO\n");
    }
    
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/