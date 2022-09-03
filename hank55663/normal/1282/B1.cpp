
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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,p,k;
        scanf("%d %d %d",&n,&p,&k);
        int a[200005];
        for(int i = 0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int Min=0,Max=n+1;
        while(Min+1<Max){
            int mid=(Max+Min)/2;
            LL tot=0;
            for(int i = mid-1;i>=0;i-=k){
                    tot+=a[i];
            }
            if(tot>p)Max=mid;
            else Min=mid;
        }
        printf("%d\n",Min);
    }
}