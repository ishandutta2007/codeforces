#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    char c[1000005];
    scanf("%s",c);
    int l=0,r=strlen(c)-1;
    vector<char> ans;
    while(l<r){
        if(r-l+1<=3){
            //L.pb(c[l]);
            for(auto it:ans){
                printf("%c",it);
            }
            printf("%c",c[l]);
            reverse(ans.begin(),ans.end());
            for(auto it:ans)
            printf("%c",it);
            printf("\n");
            return 0;
        }
        if(c[l]==c[r]){
            ans.pb(c[l]);
        }
        else if(c[l]==c[r-1]){
            ans.pb(c[l]);
        }
        else if(c[l+1]==c[r]){
            ans.pb(c[l+1]);
        }
        else if(c[l+1]==c[r-1]){
            ans.pb(c[l+1]);
        }
        l+=2;
        r-=2;
    }
    for(auto it:ans){
        printf("%c",it);
    }
   // printf("%c",c[l]);
    reverse(ans.begin(),ans.end());
    for(auto it:ans)
    printf("%c",it);
    printf("\n");
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/