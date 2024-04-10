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
    char c[15];
    scanf("%s",c);
    int ans=10;
    for(int i = 0;i<(1<<10);i++){
        char c2[15];
        for(int j = 0;j<10;j++){
            if(i&(1<<j))c2[j]='1';
            else c2[j]='0';
        }
        int ok=1;
        for(int j=0;j<10;j++){
            if(c2[j]==c[j]||c[j]=='?');
            else ok=0;
        }
        if(!ok)continue;
        int a=0,b=0;
        for(int j = 0;j<10;j++){
            if(c2[j]=='1'){
                if(j&1)b++;
                else a++;
            }
            if((10-j)/2+b<a){
                ans=min(ans,j+1);
            }
            if((10-j-1)/2+a<b){
                ans=min(ans,j+1);
            }
        }
    }
    printf("%d\n",ans);
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