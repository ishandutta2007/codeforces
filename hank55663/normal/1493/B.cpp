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
int aa[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
bool check(int h,int m,int a,int b){
    vector<int> v;
    for(int i = 0;i<2;i++){
        if(aa[b%10]==-1)return 0;
        v.pb(aa[b%10]);
        b/=10;
    }
    for(int i = 0;i<2;i++){
        if(aa[a%10]==-1)return 0;
        v.pb(aa[a%10]);
        a/=10;
    }
    if(v[0]*10+v[1]<h&&v[2]*10+v[3]<m)return true;
    return false;
}
void solve(){
    int h,m;
    scanf("%d %d",&h,&m);
    int a,b;
    scanf("%d:%d",&a,&b);
    while(true){
        if(check(h,m,a,b)){
            printf("%02d:%02d\n",a,b);
            return;
        }
        b++;
        if(b==m)a++,b=0;
        if(a==h)a=0;
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
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