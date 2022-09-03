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
    vector<int> v[5];
    for(int i = 0;i<n;i++){
        char c[400005];
        scanf("%s",c);
        int cnt[5]={0,0,0,0,0};
        for(int j  =0;c[j]!=0;j++){
            cnt[c[j]-'a']++;
        }
        int n=strlen(c);
        for(int j=0;j<5;j++){
            v[j].pb(2*cnt[j]-n);
        }
    }
    int ans=0;
    for(int i = 0;i<5;i++){
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
        int tot=0,sum=0;
        int fi=1;
        for(auto it:v[i]){
            
            if(tot+it<=0&&!fi){
                break;
            }
            fi=0;
            tot+=it;
            if(tot>0)
            sum++;
        }
        ans=max(ans,sum);
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
3 3 7 3 25
*/