#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    LL tot=0;
    string s[40];
    for(int i = 0;i<n;i++)cin>>s[i];
    reverse(s,s+n);
    for(int i = 0;i<n;i++){
        tot<<=1;
        if(s[i]=="halfplus"){
            tot++;
        }
    }
    LL ans=0;
    reverse(s,s+n);
    for(int i =0;i<n;i++){
        ans+=tot*p/2;
        tot/=2;
    }
    printf("%lld\n",ans);
}