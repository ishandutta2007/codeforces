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
    char s[505],t[1005];
    scanf("%s %s",s,t);
    for(int i = 0;s[i]!=0;i++){
        int now=0;
        for(int j =i;s[j]!=0;j++){
            if(s[j]==t[now]){
                now++;
                if(t[now]==0){
                    printf("YES\n");
                    return ;
                }
                int tnow=now;
                for(int k = j-1;k>=0;k--){
                    if(s[k]==t[tnow]){
                        tnow++;
                        if(t[tnow]==0){
                            printf("YES\n");
                            return;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                break;
            }
        }
    }
    printf("NO\n");
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