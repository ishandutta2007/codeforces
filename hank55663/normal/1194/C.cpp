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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char s[105],t[105],p[105];
        scanf("%s %s %s",s,t,p);
        int cnt[26];
        MEM(cnt);
        int now=0;
        for(int i = 0;t[i]!=0;i++){
            if(s[now]==t[i]){
                now++;
            }
            else{
                cnt[t[i]-'a']++;
            }
        }
        if(s[now]!=0){
            printf("NO\n");
            continue;
        }
        for(int i = 0;p[i]!=0;i++){
            cnt[p[i]-'a']--;
        }
        int ok=1;
        for(int i = 0;i<26;i++){
            if(cnt[i]>0)ok=0;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
}
/*
4
8
2 2 4
3 1 3 5
1 2
2 1 5
4 2 6 4 7
2 5 8
2 8 5
2 7 6
 */