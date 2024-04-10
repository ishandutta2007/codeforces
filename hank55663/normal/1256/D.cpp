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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL n,k;
        char c[1000005];
        scanf("%lld %lld %s",&n,&k,c);
        int now=0;
        LL tot=0;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='0'){
                tot+=i-now;
                swap(c[i],c[now]);
                if(tot>k){
                    swap(c[now],c[now+(tot-k)]);
                    break;
                }
                now++;
            }
        }
        printf("%s\n",c);
    }
}