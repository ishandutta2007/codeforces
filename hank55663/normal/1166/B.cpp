#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
    char c[10]="aeiou";
    int k;
    scanf("%d",&k);
    for(int i = 5;i<=k;i++){
        if(k%i==0&&k/i>=5){
            string ans;
            for(int j =0;j<i;j++){
                for(int kk=0;kk<k/i;kk++){
                    ans+=c[(j+kk)%5];
                }
            }
            cout<<ans<<endl;
            return 0;
        }
    }
    printf("-1\n");
}