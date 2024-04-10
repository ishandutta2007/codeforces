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
vector<int> v[26];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char s[100005],t[100005];
        scanf("%s %s",s,t);
        for(int i = 0;i<26;i++){
            v[i].clear();
        }
        int len=strlen(s);
        for(int i = 0;s[i]!=0;i++){
            v[s[i]-'a'].pb(i);
        }
        for(int i = 0;i<26;i++)v[i].pb(len);
        int now=0;
        int ans=1;
        for(int i = 0;t[i]!=0;i++){
            if(v[t[i]-'a'].size()==1){
                ans=-1;
                break;
            }
            int it=*lower_bound(v[t[i]-'a'].begin(),v[t[i]-'a'].end(),now);
            if(it==len){
                ans++;
                now=v[t[i]-'a'][0]+1;
            }
            else{
                now=it+1;
            }
        }
        printf("%d\n",ans);
    }
}