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
    deque<char> c;
    char s[30];
    scanf("%s",s);
    int len=strlen(s);
    for(int i = 0;s[i]!=0;i++){
        c.push_back(s[i]);
    }
    for(int i = len-1;i>=0;i--){
        if(c.front()==i+'a'){
            c.pop_front();
        }
        else if(c.back()==i+'a'){
            c.pop_back();
        }
        else{
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}