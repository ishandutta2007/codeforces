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
//#define N 262144
#define ULL unsigned long long
#define ll long long
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[505],b[505];
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i = 0;i<n;i++){
            scanf("%d",&b[i]);
        }
        int ok=1;
        if(n%2==1&&a[n/2]!=b[n/2])ok=0;
        map<pii,int> m;
        for(int i = 0;i<n/2;i++){
            if(a[i]>a[n-i-1])swap(a[i],a[n-i-1]);
            m[mp(a[i],a[n-i-1])]++;
        }
        for(int i = 0;i<n/2;i++){
            if(b[i]>b[n-i-1])swap(b[i],b[n-i-1]);
            if(--m[mp(b[i],b[n-i-1])]<0)ok=0;
        }
        if(ok)printf("Yes\n");
        else printf("No\n");
    }
}
/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/