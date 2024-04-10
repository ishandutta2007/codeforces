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
    vector<int> v;
void solve(){
    char a[100],s[100];
    scanf("%s %s",a,s);
    int an=strlen(a),sn=strlen(s);
    reverse(a,a+an);
    reverse(s,s+sn);
    vector<int> b;
    int now=0;
    for(int i = 0;a[i]!=0;i++){
        if(a[i]<=s[now])b.pb(s[now]-a[i]),now++;
        else{
            if(s[now+1]!='1'){
                printf("-1\n");
                return;
            }
            else{
                b.pb(s[now]-a[i]+10),now+=2;
            }
        }
     //   printf("%d\n",b.back());
    }
    while(s[now]!=0)b.pb(s[now]-'0'),now++;
    while(b.back()==0)b.pop_back();
    if(b.empty())b.pb(0);
//    if(s[now]!=0)printf("-1\n");
 //   else{
        reverse(b.begin(),b.end());
        for(auto it:b)printf("%d",it);
        printf("\n");
   // }
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}