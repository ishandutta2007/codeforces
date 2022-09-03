#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL h,c,t;
        scanf("%lld %lld %lld",&h,&c,&t);
        if(t*2<=(h+c)){
            printf("2\n");
        }
        else if(t==h){
            printf("1\n");
        }
        else{
            int a=h*2+c,b=h*3;
            if(t*3>=a){
                if(t*3-a>=b-t*3){
                    printf("1\n");
                }
                else{
                    printf("3\n");
                }
            }
            else{
                LL Max=1e12,Min=1;
                while(Max>Min+1){
                    LL mid=(Max+Min)/2;
                    if((mid*h+(mid-1)*c)>=(mid*2-1)*t)Min=mid;
                    else Max=mid;
                }
                if((Min*h+(Min-1)*c)*(2*Max-1)-t*(2*Max-1)*(2*Min-1)>t*(2*Max-1)*(2*Min-1)-(Max*h+(Max-1)*c)*(2*Min-1)){
                    printf("%lld\n",2*Max-1);
                }
                else{
                    printf("%lld\n",2*Min-1);
                }
            }
        }
    }
}
/*
2 11 14
9 3


000111222
001112220
*/