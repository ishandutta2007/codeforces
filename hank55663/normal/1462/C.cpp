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
using namespace std;
void solve(){
    int x;
    scanf("%d",&x);
    if(x>45){
        printf("-1\n");
    }
    else{
        for(int i = 1;i<=10;i++){
            if((9+9-i+1)*i/2>=x){
                vector<int> v;
                for(int j = 9;j<=x&&j>0;x-=j,j--){
                    v.pb(j);
                }
               // printf("%d?\n",x);
                if(x)v.pb(x);
                reverse(v.begin(),v.end());
                for(auto it:v)printf("%d",it);
                printf("\n");
                return ;
            }
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
}