#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int a[200005];
    for(int i = 0;i<n;i++)
    scanf("%d",&a[i]);
    if(k==1){
        printf("%d\n",n);
        return 0;
    }
    sort(a,a+n);
    vector<int> v;
    int ans=0;
    for(int i = 0;i<n;i++){
        if(v.size()<k-1){
            v.pb(a[i]);
        }
        else{
            if(a[i]-v[v.size()-k+1]<m){
                ans++;
            }
            else{
                v.pb(a[i]);
            }
        }
    }
    printf("%d\n",ans);
}
/*
1 8 18
2 7 17
3 6 16
4 5 15
5 14
6 13
7 12
8 11
9 10
10 19
11 18
12 17
13 16
14 15
0 ~ 2345 2
2346 ~ 9999 1
 9999
12345
*/