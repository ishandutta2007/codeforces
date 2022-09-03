#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > q[100005];
#define mp make_pair
#define x first
#define pb push_back
#define y second
void solve(){
            int n;
        scanf("%d",&n);
        char c[55];
        scanf("%s",c+1);
        int cnt=0;
        int dp[55][7][3];
        dp[0][0][0]=1;
        char qu[10]="abacaba";
        //int f[7] = {-1,-1,0,-1,0,1,2};
        for(int i = 1;c[i]!=0;i++){
            int ok=1;
            vector<int> v;
            for(int j = i;j<i+7;j++){
                if(c[j]!=qu[j-i]&&c[j]!='?')ok=0;
                if(c[j]=='?')c[j]=qu[j-i],v.pb(j);
            }  

            int cnt=0;
            for(int j = 1;c[j]!=0;j++){
                int ook=1;
                for(int k=0;k<7;k++){
                    if(qu[k]!=c[j+k])ook=0;
                }
                cnt+=ook;
            }
            if(cnt==1&&ok){
                printf("Yes\n");
                for(int j = 1;c[j]!=0;j++){
                    if(c[j]=='?')c[j]='z';
                }
                printf("%s\n",c+1);
                return;
            }
            for(auto it:v)c[it]='?';
        }
        printf("No\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/