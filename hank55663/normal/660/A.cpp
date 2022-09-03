#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
int main(){
    int n;
    scanf("%d",&n);
    int a[1005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    vector<int> v;
    v.pb(a[0]);
    for(int i = 1;i<n;i++){
        if(__gcd(v.back(),a[i])!=1){
            v.pb(1);
        }
        v.pb(a[i]);
    }
    printf("%d\n",v.size()-n);
    for(auto it:v){
        printf("%d ",it);
    }
    printf("\n");
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/