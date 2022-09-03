#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define LL long long
using namespace std;
int main(){
    LL h,n;
    scanf("%lld %lld",&h,&n);
    int d[200005];
    for(int i=0;i<n;i++){
        scanf("%d",&d[i]);
    }
    LL most=0;
    LL tot=0;
    for(int i =0;i<n;i++){
        tot-=d[i];
        most=max(most,tot);
    }
    if(tot<=0&&most<h){
        printf("-1\n");
        return 0;
    }
    LL round = 0;
    LL ans = 0;
    if(tot>0){
        round=(max(h-most,0ll)+tot-1)/tot;
        ans = round*n;
    }
    h-=round*tot;
    for(int i = 0;i<n;i++){
        h+=d[i];
        ans++;
        if(h<=0)
        break;
    }
    printf("%lld\n",ans);
}