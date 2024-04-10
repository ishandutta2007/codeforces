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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
vector<pair<int,string> > v;
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    
    if(m>1){
        v.pb(mp(m-1,"R"));
        v.pb(mp(m-1,"L"));
    }
    if(n>1)
    v.pb(mp(1,"D"));
    for(int i = 2 ;i<=n;i++){
        if(m>1){
            v.pb(mp(m-1,"R"));
            v.pb(mp(m-1,"UDL"));
        }
        if(i!=n)
        v.pb(mp(1,"D"));
    }
    if(n>1)
    v.pb(mp(n-1,"U"));
    int tot=0;
    for(auto it:v){
        tot+=it.x*it.y.size();
    }
    if(tot<k){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        vector<pair<int,string> > res;
        for(auto it:v){
            int num=min(k/(int)it.y.size(),it.x);
            if(num){
                res.pb(mp(num,it.y));
               // printf("%d %s\n",num,it.y.c_str());
            }
            it.x-=num;
            k-=num*it.y.size();
            if(it.x&&k){
                string s;
                //printf("1 ");
                for(int i = 0;i<k;i++)
                s+=it.y[i];
                //printf("%c",it.y[i]);
                k=0;
                res.pb(mp(1,s));
              //  printf("\n");
                
            }
        }
        printf("%d\n",res.size());
        for(auto it:res){
            printf("%d %s\n",it.x,it.y.c_str());
        }
    }
}