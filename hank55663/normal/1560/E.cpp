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
void solve(){
    int val[26];
    MEMS(val);
    char c[500005];
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        val[c[i]-'a']=i;
    }
    vector<pii> v;
    for(int i = 0;i<26;i++){
        if(val[i]!=-1)v.pb(mp(val[i],i));
    }
    sort(v.begin(),v.end());
    if(v.size()==1){
        printf("%s %c\n",c,c[0]);
        return;
    }
    int cnt[26];
    MEM(cnt);
    int n=strlen(c);
    for(int i = 0;c[i]!=0;i++){
        cnt[c[i]-'a']++;
       // printf("%d %d\n",v[0].x,v[1].x);
        if(i>=v[0].x&&i<v[1].x){
            int tmp[26];
            for(int j = 0;j<26;j++)tmp[j]=cnt[j];
            int tot=0,sum=i+1;
            for(auto it:v){
                tot+=sum;
                sum-=tmp[it.y];
            }
           // printf("%d %d %d\n",i,tot,n);
            if(tot==n){
                string ans;
                int vis[26];
                MEM(vis);
                for(auto it:v){
                    for(int j = 0;j<=i;j++){
                        if(!vis[c[j]-'a'])ans+=c[j];
                    }
                    vis[it.y]=1;
                }   
               // cout<<ans<<endl;
                if(ans==string(c)){
                    c[i+1]=0;
                    printf("%s ",c);
                    for(auto it:v)printf("%c",it.y+'a');
                    printf("\n");
                    return;
                }
                break;
            }
        }
    }
    printf("-1\n");
}
int main(){
    int t=1;//00;//00;
    scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/