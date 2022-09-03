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

void solve(){
    set<string> m,m2;
    int n;
    scanf("%d",&n);
    int ok=0;
    for(int i = 0;i<n;i++){
        char c[10];
        scanf("%s",c);
        m.insert(string(c));
        int n=strlen(c);
        string str=string(c);
        if(n==1)ok=1;
        if(n==2&&c[0]==c[1])ok=1;
        if(n==3&&c[0]==c[2])ok=1;
        if(n==2){
            reverse(str.begin(),str.end());
            if(m.find(str)!=m.end())ok=1;
             if(m2.find(str)!=m2.end())ok=1;
              reverse(str.begin(),str.end());
        }
        if(n==3){
              reverse(str.begin(),str.end());
            if(m.find(str)!=m.end())ok=1;
              reverse(str.begin(),str.end());
            string tmp=str.substr(1,2);
            reverse(tmp.begin(),tmp.end());
            if(m.find(tmp)!=m.end())ok=1;
              reverse(tmp.begin(),tmp.end());
            tmp=str.substr(0,2);
            m2.insert(tmp);
        }
    }
    if(ok)printf("YES\n");
    else printf("NO\n");

}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}