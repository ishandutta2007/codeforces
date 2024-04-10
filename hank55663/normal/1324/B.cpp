#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[5005];
        int cnt[5005];
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i]);
        }
        MEM(cnt);
        cnt[a[0]]++;
        int ok=0;
        for(int i = 2;i<n;i++){
            if(cnt[a[i]]){
                ok=1;
                //printf("YES\n");
            }
            cnt[a[i-1]]++;
        }
        if(ok){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
/*
4+3+3+4+3+2+2+1
*/