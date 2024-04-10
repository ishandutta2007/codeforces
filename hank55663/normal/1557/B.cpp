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
    int n,k;
    scanf("%d %d",&n,&k);
    int a[100005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    int ok=1;
    for(int i = 1;i<n;i++){
        if(a[i]<a[i-1])ok=0;
    }
    if(ok)printf("Yes\n");
    else{
        map<int,int> m;
        for(int i = 0;i<n;i++)m[a[i]];
        int index=0;
        for(auto &it:m)it.y=++index;
        for(int i = 0;i<n;i++)a[i]=m[a[i]];
        int cnt=1;
        for(int i = 1;i<n;i++){
            if(a[i]!=a[i-1]+1)cnt++;
        }
        if(cnt<=k)printf("YES\n");
        else printf("NO\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

10 10 40000
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 1
*/