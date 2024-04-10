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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=1e9+7;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
            char c[100005];
        scanf("%s",c);
    if(n%k){
        printf("-1\n");
    }
    else{

        int cnt[26];
        MEM(cnt);
        for(int i = 0;c[i]!=0;i++){
            cnt[c[i]-'a']++;
        }
        int ok=1;
        for(int j = 0;j<26;j++){
            if(cnt[j]%k)ok=0;
        }
        if(ok){
            printf("%s\n",c);
        }
        else{
            int tot=0;
            for(int i=n-1;i>=0;i--){
                cnt[c[i]-'a']--;
                for(int j=c[i]-'a'+1;j<26;j++){
                    cnt[j]++;
                    int tot2=0;
                    for(int kk = 0;kk<26;kk++){
                        tot2+=(k-cnt[kk]%k)%k;
                    }
                    if(tot2<=tot){
                        vector<char> v;
                        for(int kk=0;kk<26;kk++){
                            for(int _=0;_<(k-cnt[kk]%k)%k;_++){
                                v.pb(kk+'a');
                            }
                        }
                        while(v.size()<tot)v.pb('a');
                        sort(v.begin(),v.end());
                        for(int a=0;a<i;a++)printf("%c",c[a]);
                        printf("%c",j+'a');
                        for(auto it:v)printf("%c",it);
                        printf("\n");
                        return;
                    }
                    cnt[j]--;
                }
                tot++;
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
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

a b c
b c
ab ac bc
5
4 3
1 4
4 2
3 4
0 0
*/