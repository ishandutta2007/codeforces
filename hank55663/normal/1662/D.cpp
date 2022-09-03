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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    char c[205],s[205];
    scanf("%s %s",c,s);
    vector<char> v1,v2;
    int val1=0,val2=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='B')val1^=1;
        else{
            if(v1.size()&&v1.back()==c[i])v1.pop_back();
            else v1.pb(c[i]);
        }
    }
    swap(v1,v2);
    swap(val1,val2);
    for(int i = 0;s[i]!=0;i++){
        if(s[i]=='B')val1^=1;
        else{
            if(v1.size()&&v1.back()==s[i])v1.pop_back();
            else v1.pb(s[i]);
        }
    }
    if(v1==v2&&val1==val2)printf("YES\n");
    else printf("NO\n");
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/