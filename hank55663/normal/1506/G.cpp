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
    char c[200005];
    scanf("%s",c+1);
    int n=strlen(c+1);
    set<int> s;
    for(int i = 0;i<26;i++)v[i].clear();
    for(int i = 1;c[i]!=0;i++){
        for(int j = 0;j<26;j++)cnt[i][j]=cnt[i-1][j];
        cnt[i][c[i]-'a']++;
        s.insert(-(int)(c[i]-'a'));
        v[c[i]-'a'].pb(i);
    }
    int now=0;
    string ans;
    while(s.size()){
        for(auto it:s){
            auto idx=*lower_bound(v[-it].begin(),v[-it].end(),now);
            int ok=1;
            for(auto it2:s){
                if(cnt[n][-it2]-cnt[idx][-it2]==0&&it2!=it)ok=0;
            }
            if(ok){
                ans+=(char)(-it+'a');
                now=idx;
                s.erase(it);
                break;
            }
        }//printf("%d\n",now);
         // cout<<ans<<endl;
         // getchar();
    }
    cout<<ans<<endl;
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