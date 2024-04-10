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
    char s[100005],t[100005];
    scanf("%s %s",s,t);
    vector<int> st;
    for(int i = 0;s[i]!=0;i++){
        if(s[i]==t[0]){
            st.pb(i);
            //break;
        }
    }
    if(st.empty()){
        printf("NO\n");
    }
    else{
        int cnt[2]={0,0};
        for(auto it:st){
           
            if(cnt[it&1])continue;
             //printf("%d\n",it);
            cnt[it&1]=1;
            int now=0;
            for(int i = it;s[i]!=0;i++){
                if(s[i]==t[now]){
                    now++;
                    if(t[now]==0){
                        int tot=0;
                        for(int j = i+1;s[j]!=0;j++)tot++;
                        if(tot%2==0){
                            printf("YES\n");
                            return;
                        }
                        else{
                            break;
                        }
                    }
                }
                else{
                    i++;
                    if(s[i]==0)break;
                }
            }
        }
        printf("NO\n");
    }
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