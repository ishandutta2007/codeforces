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
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    char c[1005];
    scanf("%s",c);
    for(char i='a';i<='z';i++){
        int ok=1;
        for(int j = 0;c[j]!=0;j++){
            if(c[j]==i)ok=0;
        }
        if(ok){
            printf("%c\n",i);
            return;
        }
    }
     for(char i='a';i<='z';i++){
         for(char j='a';j<='z';j++){
            int ok=1;
            for(int a = 0;c[a+1]!=0;a++){
                if(c[a]==i&&c[a+1]==j)ok=0;
            }
            if(ok){
                printf("%c%c\n",i,j);
                return;
            }
         }
    }
    for(char i='a';i<='z';i++){
         for(char j='a';j<='z';j++){
             for(char k='a';k<='z';k++){
                int ok=1;
                for(int a = 0;c[a+2]!=0;a++){
                    if(c[a]==i&&c[a+1]==j&&c[a+2]==k)ok=0;
                }
                if(ok){
                    printf("%c%c%c\n",i,j,k);
                    return;
                }
             }
         }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/