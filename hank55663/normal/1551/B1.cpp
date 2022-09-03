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
    char c[100];
    scanf("%s",c);
    int cnt[26];
    fill(cnt,cnt+26,0);
    for(int i = 0;c[i]!=0;i++)cnt[c[i]-'a']++;
    int ans=0;
    int tot=0;
    for(int i = 0;i<26;i++){
        if(cnt[i]>=2)ans++;
        else if(cnt[i]==1)tot++;
    }
    printf("%d\n",ans+tot/2);
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
3 3 7 3 25
*/