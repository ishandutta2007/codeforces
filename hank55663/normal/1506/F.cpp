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
int cnt[200005][26];
vector<int> v[26];
void solve(){
    int n;
    scanf("%d",&n);
    pii p[200005];
    for(int i = 0;i<n;i++)scanf("%d",&p[i].x);
    for(int i = 0;i<n;i++)scanf("%d",&p[i].y);
    sort(p,p+n);
    int nowx=1,nowy=1;
    int res=0;
    for(int i = 0;i<n;i++){
        int need=p[i].y-nowy;
        int tot=p[i].x-nowx;
        if(need==tot){
            if((nowx+nowy)%2==0)res+=tot;
        }
        else if(need==0){
            res+=(tot)/2;
            if(tot%2&&(nowx+nowy)%2==1)res++;
        }
        else{
            res+=(tot-need)/2;
            if((tot-need)%2&&(nowx+nowy)%2)res++;
        }
        nowx=p[i].x;
        nowy=p[i].y;
        //printf("%d\n",res);
    }
    printf("%d\n",res);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
*/