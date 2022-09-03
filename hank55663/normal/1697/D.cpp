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
#define index Index
#define MXN 300000
const int mod=998244353;
int last[26];
void solve(){
    int n;
    scanf("%d",&n);
    int pre[1005];
    /*for(int i = 2;i<=n;i++){
        printf("? 2 %d %d\n",i-1,i);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x==1)pre[i]=i-1;
        else pre[i]=i;
    }*/
    MEMS(last);
    printf("? 1 %d\n",1);
    char c[1005];
    c[n+1]=0;
    fflush(stdout);
    scanf(" %c",&c[1]);
    last[c[1]-'a']=1;
    for(int i = 2;i<=n;i++){
        vector<pii> v;
        for(int j=0;j<26;j++){
            if(last[j]!=-1)v.pb(mp(last[j],j));
        }
        sort(v.begin(),v.end());
        int Min=-1,Max=v.size();
        while(Min+1<Max){
            int mid=(Max+Min)/2;
            printf("? 2 %d %d\n",v[mid].x,i);
            fflush(stdout);
            int x;
            scanf("%d",&x);
            if(x==v.size()-mid)Min=mid;
            else Max=mid;
        }
        if(Min==-1){
            printf("? 1 %d\n",i);
            fflush(stdout);
            scanf(" %c",&c[i]);
        }
        else{
            c[i]=v[Min].y+'a';
        }
        last[c[i]-'a']=i;
    }
    printf("! %s\n",c+1);
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
   // scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}