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
const int mod=1e9+7;
void solve(){
    int n;
    scanf("%d",&n);
    char c[1000005],c2[1000005];
    scanf("%s %s",c,c2);
    if(c[0]!=c2[0]){
        for(int j=0;j<n;j++)printf("1");
        printf("\n");
        return;
    }
    string s1(c),s2(c2);
    if(s1==s2){
        printf("%s\n",s1.c_str());
        return;
    }
    s1.back()++;
    for(int i = s1.size()-1;i>=0;i--){
        if(s1[i]=='2'){
            s1[i]='0';
            s1[i-1]++;
        }
        else{
            break;
        }
    }
    if(s1==s2){
        printf("%s\n",s2.c_str());
    }
    else{
        if(s2.back()=='0')s2.back()++;
         printf("%s\n",s2.c_str());
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

a b c
b c
ab ac bc
5
4 3
1 4
4 2
3 4
0 0
*/