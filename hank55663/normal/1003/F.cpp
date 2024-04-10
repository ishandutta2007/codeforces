#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
LL mod;
int base=123;
LL hash(string s){
    LL res=0;
    for(auto it:s){
        res*=base;
        res+=it-'a';
        res%=mod;
    }
    return res;
}
int main(){
    srand(time(NULL));
    mod=(LL)(rand()%2000000000+1)*1000+rand();
    while(1){
        int ok=1;
        for(LL i=2;i*i<=mod;i++)
        if(mod%i==0){
            mod++;
            ok=0;
        }
        if(ok)
        break;
    }
    int n;
    scanf("%d",&n);
    int len[305];
    LL val[305];
    int sum=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        val[i]=hash(s);
        len[i]=s.length();
        sum+=len[i]+1;
    }
    sum--;
    int ans=sum;
    for(int i=0;i<n;i++){
        int match[305];
        for(int j=i+1;j<n;j++){
            match[j]=0;
            for(int k=0;k<j-i&&j+k<n;k++){
                if(val[i+k]!=val[j+k]||len[i+k]!=len[j+k])
                    break;
                match[j]=k+1;
            }
          //  printf("%d ",match[j]);
        }
       // printf("\n");
        int len1=0;
        for(int j=1;i+j<=n;j++){
            len1+=len[i+j-1];
            int cnt=1;
            for(int k=i+j;k<n;k++){
                if(match[k]>=j){
                    cnt++;
                    k+=j-1;
                }
            }
            if(cnt>1)
            ans=min(ans,sum-cnt*len1+j*cnt);
            len1++;
        }
    }
    printf("%d\n",ans);
    return 0;
}