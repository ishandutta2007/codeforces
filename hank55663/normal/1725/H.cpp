#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
    int cnt[3]={0,0,0};
    int a[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]%3]++;
    }
    if(cnt[0]<=n/2){
        printf("0\n");
        int x=n/2-cnt[0],b=n/2;
        for(int i = 0;i<n;i++){
            if(a[i]%3==0)printf("0");
            else if(x){
                printf("0");
                x--;
            }
            else printf("1");
        }
        printf("\n");
    }
    else{
        printf("2\n");
        int x=n/2;
        for(int i = 0;i<n;i++){
            if(a[i]%3==0){
                if(x)printf("0"),x--;
                else printf("1");
            }
            else printf("1");
        }
        printf("\n");
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
*/