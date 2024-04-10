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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
map<int,multiset<LL> > s;
int mod;
int base=123;
LL Hash(char *c){
    LL sum=0;
    for(int i = 1;c[i]!=0;i++){
        sum=(sum*base+c[i]-'a')%mod;
    }   
    //printf("%lld\n",sum);
    return sum;
}
LL h[300005];
LL b[300005];
void Ha(char *c){
    h[0]=0;
    for(int i=1;c[i]!=0;i++){
        h[i]=(h[i-1]*base+c[i]-'a')%mod;
    }
}
LL getHa(int l,int r){
    return ((h[r]-h[l-1]*b[r-l+1])%mod+mod)%mod;
}
int main(){
    srand(time(NULL));
    mod=1e9+rand()%1000000000;
    while(true){
        int ok=1;
        for(int i = 2;i*i<=mod;i++){
            if(mod%i==0){
                ok=0;
                break;
            }
        }  
        if(ok)break;
        mod++;
    }
    b[0]=1;
    for(int i = 1;i<300005;i++)
        b[i]=b[i-1]*base%mod;
    int t;
    scanf("%d",&t);
    while(t--){
        int op;
        char c[300005];
        scanf("%d %s",&op,c+1);
        int len=strlen(c+1);
        if(op==1){
            s[len].insert(Hash(c));
        }
        else if(op==2){
            LL H=Hash(c);
            s[len].erase(s[len].find(H));
        }
        else{
            Ha(c);
            LL ans=0;
            for(auto& it:s){
                if(it.x>len)break;
              //  printf("%d\n",it.x);
                for(int j=it.x;c[j]!=0;j++){
                    LL H=getHa(j-it.x+1,j);
                   // printf("%lld\n",H);
                    if(it.y.find(H)!=it.y.end())ans++;
                }
            }
            printf("%lld\n",ans);
            fflush(stdout);
        }
    }
 
}