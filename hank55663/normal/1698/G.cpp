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
#define double long double
using namespace std;
LL b;
LL highbit(LL x){
    for(int i = 60;i>=0;i--){
        if(x&(1ll<<i))return i;
    }
}
void solve(){  
    char c[40];
    scanf("%s",c);
    int ok=0;
    LL lcm=1;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='1'){
            ok++;
            /*printf("%d ",i);
            if(i!=0){
                lcm=lcm*(i+1)/__gcd(lcm,(i+1)*1ll);
            }*/
        }
    }
    //printf("%lld\n",lcm);
    if(ok){
        if(ok==1){
            for(int i = 0;c[i]!=0;i++){
                if(c[i]=='1'){
                    printf("%d %d\n",i+1,i+2);
                    return;
                }
            }
        }
        else{
            LL b2;
            int st=0;
            LL now=1;
            for(int i = 0;c[i]!=0;i++){
                if(c[i]=='1'){
                    st=i+1;
                    b2=1;
                    b=0;
                    for(int j = i+1;c[j]!=0;j++){
                        if(c[j]=='1'){
                            b2|=1ll<<(j-i);
                            b|=1ll<<(j-i-1);
                        }
                    }
                    break;
                }
            }
            LL tmp=1;
            LL hi=highbit(b2);
            map<LL,int> m;
            for(int i = 0;i<=400000;i++){
                if(highbit(tmp)==hi)tmp^=b2;
                  if(m.find(tmp)==m.end()){
                    m[tmp]=i;
                //    printf("%lld %d\n",tmp,i);
                }
                tmp<<=1;
              
            }

            while((b&-b)!=b&&now<=300000){
                LL x=__builtin_popcountll((b&-b)-1);//._Find_first();
                b/=(b&-b);//(b&-b);
                b^=b2;
                now+=x;
              /*  b^=b2;
                if(now>2080374754){
                    assert(0);
                }*/
              /*  if(now>1e8){
                 //  printf("-1\n");
                    return;
                }*/
            }
           /* if((b&-b)==b){
             LL x=__builtin_popcountll((b&-b)-1);
                    b>>=x;
                    now+=x;
                printf("%d %lld\n",st,now+st);
            }
            else*/{
                LL x=__builtin_popcountll((b&-b)-1);//._Find_first();
                b/=(b&-b);//(b&-b);
                now+=x;
               // printf("%lld\n",b);
                LL res=now;
                LL add=b;
                for(int i = 0;i<1000000;i++){
                    while(highbit(b)>highbit(add)){
                        res++;
                        if(b&1)b^=b2;
                        b>>=1;
                    }
                    if(m.find(b)!=m.end()){
                        printf("%d %lld\n",st,res+m[b]+st);
                        return;
                    }
                    LL tmp=0;
                    LL sub=0;
                    res+=now;
                    for(int j = 0;j<40;j++){
                        if(b&(1ll<<j)){
                            while(j-sub>20){
                                sub++;
                                res++;
                                if(tmp&1){
                                    tmp^=b2;
                                }
                                tmp>>=1;
                            }
                            tmp^=add<<(j-sub);
                        
                      
                        }
                    }
                    b=tmp;
                   // printf("%lld\n",b);
                }
                printf("-1\n");
            }
        }
    }
    else{
        printf("-1\n");
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/