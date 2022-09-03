#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
#define N 6000005
#define rank Rank
int cnt[200005][26];
int main(){
    char s[200005];
    scanf("%s",s+1);
    for(int i = 1;s[i]!=0;i++){
        for(int j=0;j<26;j++)cnt[i][j]=cnt[i-1][j];
        cnt[i][s[i]-'a']++;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        if(l==r){
            printf("Yes\n");
        }
        else{
            if(s[l]!=s[r]){
                printf("Yes\n");
            }
            else{
                int tot=0;
                for(int i = 0;i<26;i++){
                    if(cnt[r][i]-cnt[l-1][i])tot++;
                }
                if(tot>2)
                printf("Yes\n");
                else
                printf("No\n");
            }
        }
    }
}