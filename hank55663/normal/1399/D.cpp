#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char c[200005];
        scanf("%s",c);
        vector<int> cnt[2];//={0,0};
        int tot=0;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(cnt[1-(c[i]-'0')].size()){
               ans.pb(cnt[1-(c[i]-'0')].back());
               cnt[c[i]-'0'].pb(cnt[1-(c[i]-'0')].back());
               cnt[1-(c[i]-'0')].pop_back();
            }
            else{
                tot++;
                ans.pb(tot);
                cnt[c[i]-'0'].pb(tot);
            }
             //cnt[c[i]-'0']++;
        }
        printf("%d\n",tot);
        for(auto it :ans){
            printf("%d ",it);
        }
        printf("\n");
    }
}