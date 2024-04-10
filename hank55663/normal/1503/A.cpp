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
const int mod=1e9+7;

void solve(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c);
    vector<char> v1,v2;
    int sum1=0,sum2=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='1'){
            sum1++;
        }
        else{
            sum2++;
        }
    }
    if(sum1%2!=0){
        printf("NO\n");
    }
    else{
        int a=0,b=0;
        sum1/=2;
        int last=0;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='1'){
                if(sum1){
                    sum1--;
                    v1.pb('(');
                    v2.pb('(');
                    a++;b++;
                }
                else{
                    v1.pb(')');
                    v2.pb(')');
                    a--;
                    b--;
                }
            }
            else{
                if(last){
                    v1.pb('(');
                    v2.pb(')');
                    a++;
                    b--;
                }
                else{
                    v1.pb(')');
                    v2.pb('(');
                    a--;
                    b++;
                }
                last^=1;
            }
            if(a<0||b<0){
                printf("NO\n");
                return;
            }
        }
        printf("YES\n");
        for(auto it:v1)printf("%c",it);
        printf("\n");
        for(auto it:v2)printf("%c",it);
        printf("\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}