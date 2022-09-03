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
int a[1000005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    vector<pair<double,int> > v;
    for(int i = 1;i<=n;i++){
        double tot=a[i];
        int sum=1;
        while(!v.empty()&&v.back().x>tot/sum){
            tot+=v.back().x*v.back().y;
            sum+=v.back().y;
            v.pop_back();
        }
       // tot+=a[i];
       // sum++;
        v.pb(mp(tot/sum,sum));
    }
    for(auto it:v){
        for(int j=0;j<it.y;j++){
            printf("%.12f\n",it.x);
        }
    }
    
}