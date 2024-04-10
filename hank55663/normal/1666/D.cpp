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
void solve(){
    char c[100005],c2[1000005];
    int cnt[26];
    fill(cnt,cnt+26,0);
    scanf("%s %s",c,c2);
    vector<char> v;
    for(int i = 0;c2[i]!=0;i++)cnt[c2[i]-'A']++;
    for(int i = strlen(c)-1;i>=0;i--){
        if(cnt[c[i]-'A']){
            v.pb(c[i]);
            cnt[c[i]-'A']--;
        }
    }
    reverse(v.begin(),v.end());
    if(v.size()==strlen(c2)){
        for(int i = 0;i<v.size();i++){
            if(c2[i]!=v[i]){
                printf("NO\n");
                return;
            }
        }
        printf("YES\n");
        return;
    }
    printf("NO\n");
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/