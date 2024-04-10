#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
void solve(){
    int n;
    scanf("%d",&n);
    char c[500005];
    scanf("%s",c);
    int now=0,cnt=0,tot=0;
    for(int i = 0;c[i]!=0;i++){
        //now++;
        if(!now&&c[i]=='('&&c[i+1]!=0){
            now=0;
            i++;
            cnt++;

        }
        else if(c[i]==')'){
            if(now>=1){
                cnt++;
                now=0;
            }
            else{
                now++;
            }
        }
        else{
            now++;
        }
    }
    printf("%d %d\n",cnt,now);
}


int main(){
    int t=1;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/