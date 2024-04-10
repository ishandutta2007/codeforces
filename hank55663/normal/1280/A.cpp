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
//#define N 6000005
#define rank Rank
#define index Index
int mod=1e9+7;
int main() {
    int t;
    scanf("%d",&t);
    char c[5000005];
    while(t--){
        int x;
        scanf("%d",&x);
        fill(c,c+x+10,0);
        scanf("%s",c);
        
        LL len=strlen(c);
        int slen=strlen(c);
        int l=0;
        while(true){
            if(slen<x){
                int tmp=slen;
                for(int i = 1;i<c[l]-'0';i++){
                    for(int j=l+1;j<tmp;j++){
                        c[slen++]=c[j];
                        c[slen]=0;
                        if(slen>=x+10)
                        break;
                    }
                    if(slen>=x+10)
                    break;
                }
             //   printf("%s\n",c);
            }
            l++;
            len=(len-l)*(c[l-1]-'0')+l;
            len=len%mod;
        //    printf("%d\n",len);
            if(l==x)break;
        }
        printf("%lld\n",(len%mod+mod)%mod);
    }
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/