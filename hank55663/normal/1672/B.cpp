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
    char c[200005];
    scanf("%s",c);
    int n=strlen(c);
    if(c[n-1]=='A'){
        printf("NO\n");
    }
    else{
        int cnt=0;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='A')cnt++;
            else cnt--;
            if(cnt<0)break;
        }
        if(cnt<0)printf("NO\n");
        else printf("YES\n");
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
*/