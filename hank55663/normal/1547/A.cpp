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
#define last Last
#define MXN 200005
void solve(){
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    if(a!=c&&b!=d){
        printf("%d\n",abs(a-c)+abs(b-d));
    }
    else{
        if(a==c&&e==a){
            if(f>b&&f<d){
                 printf("%d\n",abs(a-c)+abs(b-d)+2);
            }
            else if(f>d&&f<b){
                 printf("%d\n",abs(a-c)+abs(b-d)+2);
            }
            else{
                 printf("%d\n",abs(a-c)+abs(b-d));
            }
        }
        else if(b==d&&f==b){
            if(a>e&&e>c){
                 printf("%d\n",abs(a-c)+abs(b-d)+2);
            }
            else if(a<e&&e<c){
                 printf("%d\n",abs(a-c)+abs(b-d)+2);
            }
            else{
                 printf("%d\n",abs(a-c)+abs(b-d));
            }
        }
        else{
             printf("%d\n",abs(a-c)+abs(b-d));
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}