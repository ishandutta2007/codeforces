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
static const double INF = 2147483647;
void solve(){
    char c[100005];
    scanf("%s",c);
    int cnt[26];
    fill(cnt,cnt+26,0);
    for(int i= 0;c[i]!=0;i++){
        cnt[c[i]-'a']++;
    }
    for(int i = 0;i<26;i++){
        if(cnt[i]==1){
            printf("%c",i+'a');
            cnt[i]--;
            for(int j=0;j<26;j++){
                while(cnt[j]--)printf("%c",j+'a');
            }
            printf("\n");
            return;
        }
    }
    int Min;
    for(int i = 0;i<26;i++){
        if(cnt[i]){
            Min=i;
            break;
        }
    }
    int n=strlen(c);
    if(cnt[Min]+cnt[Min]-2<=n){
        printf("%c%c",Min+'a',Min+'a');
        cnt[Min]-=2;
        for(int i=2;i<n;i++){
            if(i%2==0){
                for(int j = Min+1;j<26;j++){
                    if(cnt[j]){
                        printf("%c",j+'a');
                        cnt[j]--;
                        break;
                    }
                }
            }
            else{
                for(int j = Min;j<26;j++){
                    if(cnt[j]){
                        printf("%c",j+'a');
                        cnt[j]--;
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
    else{
        if(cnt[Min]==n){
            for(int i = 0;i<n;i++)printf("%c",Min+'a');
            printf("\n");
        }
        else{
            int tot=0;
            for(int i = 0;i<26;i++)if(cnt[i])tot++;
            if(tot>=3){
              //  printf("!\n");
                
                printf("%c",Min+'a');
                cnt[Min]--;
                int last;
                for(int i = Min+1;i<26;i++){
                    if(cnt[i]){
                        last=i;
                        printf("%c",i+'a');
                        cnt[i]--;
                        break;
                    }
                }
                while(cnt[Min]--)printf("%c",Min+'a');
                for(int i = last+1;i<26;i++){
                    if(cnt[i]){
                        printf("%c",i+'a');
                        cnt[i]--;
                        break;
                    }
                }
                for(int j=Min+1;j<26;j++){
                    while(cnt[j]--)printf("%c",j+'a');
                }
                printf("\n");
            }
            else{
                printf("%c",Min+'a');
                cnt[Min]--;
                for(int i = Min+1;i<26;i++){
                    while(cnt[i]--)printf("%c",i+'a');
                }
                while(cnt[Min]--)printf("%c",Min+'a');
                printf("\n");
            }
        }
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