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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
#define MXN 10000
void solve(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c);
    int sum=0;
   // int l;
    int rev=0;
    vector<pii> v;
    int val[200005];
    int ok=1;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='(')sum++;
        else sum--;
        while(v.size()&&v.back().x<=sum){
            v.pop_back();
        }
        v.pb(mp(sum,i));
        val[i]=sum;
        if(sum<0){
            ok=0;
        }
    }
    if(ok){
        printf("0\n");
    }
    else{
        int Max=0,Maxi=-1;
        for(int i = 0;c[i]!=0;i++){
            if(val[i]>Max){
                Max=val[i];
                Maxi=i;
            }
            if(val[i]<0)break;
        }
        int Max2=0,Max2i=2*n-1;
        for(int i = 2*n-1;i>=0;i--){
            if(val[i]>Max2){
                Max2=val[i];
                Max2i=i;
            }
            if(val[i]<0)break;
        }
        reverse(c+Maxi+1,c+Max2i+1);
        int sum=0,ok=1;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='('){
                sum++;
            }
            else{
                sum--;
            }
            if(sum<0)ok=0;
        }
        if(ok){
            printf("1\n");
            printf("%d %d\n",Maxi+1+1,Max2i+1);
        }
        else{
            printf("2\n");
            int Max=0,Maxi;
            for(int i = 0;c[i]!=0;i++){
                if(val[i]>Max){
                    Max=val[i];
                    Maxi=i;
                }
                //if(val[i]<0)break;
            }
            printf("%d %d\n",1,Maxi+1);
            printf("%d %d\n",Maxi+2,2*n);
        }
    }

}
int main(){
   // srand(time(NULL));
    int t=1;;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}