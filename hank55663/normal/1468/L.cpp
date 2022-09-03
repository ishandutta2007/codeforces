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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
LL f_pow(LL a,LL b,LL mod){
    __int128 res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
bool Isprime(LL n){
    if(n==2)return true;
    if(n<2||n%2==0)return false;
    LL u = n-1,t=0;
    while(u%2==0){u>>=1;t++;}
    LL sprp[7]={2,325,9375,28178,450775,9780504,1795265022};
    for(int k = 0;k<7;k++){
        LL a=sprp[k]%n;
        if(a==0||a==1||a==n-1)continue;
        LL x=f_pow(a,u,n);
        if(x==1||x==n-1)continue;
        for(int i = 0;i<t-1;i++){
            x=f_pow(x,2,n);
            if(x==1)return false;
            if(x==n-1)break;
        }
        if(x==n-1)continue;
        return false;
    }
    return true;
}
inline LL f(LL x,LL mod){
    return ((__int128)x*x%mod+1)%mod;
}
inline LL pollard_rho(LL n){
    if(!(n&1))return 2;
    while(true){
        LL y=2,x=rand()%(n-1)+1,res=1;
        for(int sz=2;res==1;sz*=2){
            for(int i = 0;i<sz&&res<=1;i++){
                x=f(x,n);
                res=__gcd(abs(x-y),n);
            }
            y=x;
        }
        if(res!=0&&res!=n)return res;
    }
}
set<LL> s;
void go(LL n){
    if(Isprime(n))s.insert(n);
    else{
        LL x=pollard_rho(n);
        go(x);
        go(n/x);
    }
}
set<LL> factor[1005];
map<LL,vector<int> > m;
map<LL,vector<int> > v;

vector<LL> tprime;
void Find(){
    LL isprime[1000005];
    fill(isprime,isprime+1000005,1);
    for(int i = 2;i<1000005;i++){
        if(isprime[i]){
            tprime.pb(i);
            for(int j = i*2;j<1000005;j+=i){
                isprime[j]=0;
            }
        }
    }
}
LL degree[1005];
LL ok[1005];
bool solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    LL x[1005];
    LL tmpx[1005];
    map<LL,LL> s[65];
    Find();
   // printf("%lld\n",tprime[tprime.size()-2]);
    for(int i = 3;i<60;i++){
        for(auto it:tprime){
            __int128 tmp=1;
            for(int j = 0;j<i;j++){
                tmp*=it;
                if(tmp>1e18)break;
            }
            if(tmp<1e18)s[i][tmp]=it;
        }
    }
    vector<LL> prime;
    for(int i = 0;i<n;i++){
        //x[i]=rand()*1000000000ll+rand();
       // if(x[i]%2==0)x[i]++;
      //  printf("%lld\n",x[i]);
        scanf("%lld",&x[i]);
        for(int j = 3;j<60;j++){
            if(s[j].find(x[i])!=s[j].end()){
                ok[i]=1;
                factor[i].insert(s[j][x[i]]);
                prime.pb(s[j][x[i]]);
            }
        }
        if(!ok[i]){
            if(Isprime(x[i])){
                factor[i].insert(x[i]);
                prime.pb(x[i]);
                ok[i]=1;
            }
            else{
                LL Min=1,Max=1e9;
                while(Max>Min+1){
                    LL mid=(Max+Min)/2;
                    if(mid*mid>x[i])Max=mid;
                    else Min=mid;
                }
                if(Min*Min==x[i]&&Isprime(Min)){
                    factor[i].insert(Min);
                    prime.pb(Min);
                    ok[i]=1;
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
       // go(x[i]);
      //  factor[i]=s;
        if(ok[i]){
            LL fac=*factor[i].begin();
            if(m[fac].size()<2)m[fac].pb(i);
            else v[fac].pb(i),degree[i]++;
        }
        else{
            tmpx[i]=x[i];
            for(auto it:prime){
                while(tmpx[i]%it==0){
                    factor[i].insert(it);
                    tmpx[i]/=it;
                }
            }
            if(tmpx[i]==1){
                ok[i]=1;
                for(auto it:factor[i]){
                    v[it].pb(i);
                    degree[i]++;
                }
            }
        }
        //s.clear();
    }
    LL Min=1e9;
    LL Mini;
    for(int i = 0;i<n;i++){
        if(!ok[i])continue;
        if(degree[i]){
            int ok=1;
            for(auto it:factor[i]){
                if(m[it].size()!=2)ok=0;
            }
            if(ok){
                Min=min(Min,degree[i]*2+1);
                if(Min==degree[i]*2+1){
                    Mini=i;
                }
            }
        }
    }
    if(k%2==1){
        if(k<Min){
            printf("0\n");
        }
        else{
            vector<int> ans;
            queue<int> q;
            for(auto it:factor[Mini]){
                ans.pb(m[it][0]);
                ans.pb(m[it][1]);
                for(auto it2:v[it]){
                    if(--degree[it2]==0&&it2!=Mini)q.push(it2);
                }
                m.erase(it);
            }
            ans.pb(Mini);
            for(auto it:m){
                if(it.y.size()==2){
                    ans.pb(it.y[0]);
                    ans.pb(it.y[1]);
                    for(auto it2:v[it.x]){
                        if(--degree[it2]==0)q.push(it2);
                    }
                }
            }
            while(!q.empty()){
                ans.pb(q.front());
                q.pop();
            }
            if(ans.size()<k)printf("0\n");
            else{
                for(int j = 0;j<k;j++){
                    printf("%lld ",x[ans[j]]);
                }
            }
        }
    }
    else{
        vector<int> ans;
        queue<int> q;
        for(auto it:m){
            if(it.y.size()==2){
                ans.pb(it.y[0]);
                ans.pb(it.y[1]);
                for(auto it2:v[it.x]){
                    if(--degree[it2]==0)q.push(it2);
                }
            }
        }
        while(!q.empty()){
            ans.pb(q.front());
            q.pop();
        }
         if(ans.size()<k)printf("0\n");
            else{
                for(int j = 0;j<k;j++){
                    printf("%lld ",x[ans[j]]);
                }
            }
    }
    return true;
}
int main(){
    int t=1;00000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/