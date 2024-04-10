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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char p[1005],h[1005];
        scanf("%s %s",p,h);
        int cnt[26];
        fill(cnt,cnt+26,0);
        for(int i = 0;p[i]!=0;i++)
            cnt[p[i]-'a']++;
        int now[26];
        int len=strlen(p);
        if(strlen(h)<len){
            printf("NO\n");
            continue;
        }
        fill(now,now+26,0);
        for(int i = 0;i<len-1;i++){
            now[h[i]-'a']++;
        }
        int ook=0;
        for(int i = len-1;h[i]!=0;i++){
            now[h[i]-'a']++;
            int ok=1;
            for(int j=0;j<26;j++){
                if(now[j]!=cnt[j])ok=0;
            }
            if(ok){
                printf("YES\n");
                ook=1;
              //  printf("%d\n",i);
                break;
            }
            now[h[i-len+1]-'a']--;
        }
        if(!ook){
            printf("NO\n");
        }
    }
}