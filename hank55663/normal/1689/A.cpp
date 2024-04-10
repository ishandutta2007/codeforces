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
#define index Index
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    char a[105],b[105];
    scanf("%s %s",a,b);
    sort(a,a+n);
    sort(b,b+m);
    vector<char> v;
    int l=0,r=0,cnt=0,now=0;
    while(l!=n&&r!=m){
        if(now==k){
            if(cnt==0)v.pb(b[r++]);
            else v.pb(a[l++]);
            cnt^=1;now=1;
            continue;
        }
        if(a[l]<b[r]){
            v.pb(a[l++]);
            if(cnt==0)now++;
            else cnt=0,now=1;
        }
        else{
            v.pb(b[r++]);
            if(cnt==1)now++;
            else cnt=1,now=1;
        }
    }
    for(auto it:v)printf("%c",it);
    printf("\n");
}

int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}