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
vector<pii> v;
int p[300005];
int loc[300005];
void myswap(int a,int b){
    v.pb(mp(a,b));
    swap(p[a],p[b]);
    loc[p[a]]=a;
    loc[p[b]]=b;
}
int main(){
    int n;
    scanf("%d",&n);

    for(int i = 1;i<=n;i++){
        scanf("%d",&p[i]);
        loc[p[i]]=i;
    }

    for(int i = 1;i<=n/2;i++){
        if(loc[i]<=n/2){
            myswap(loc[i],n);
        }
        if(loc[i]>n/2){
            int a=loc[i];
            myswap(loc[i],i);
        }
        int a=i,b=n/2+i;
        myswap(i,n/2+i);
        if(loc[n/2+i]<=n/2){
            myswap(loc[n/2+i],n);
        }
        if(loc[n/2+i]>n/2){
            myswap(loc[n/2+i],i);
        }
        myswap(a,b);
    }
    printf("%d\n",v.size());
    for(auto it:v)
    printf("%d %d\n",it.x,it.y);
    for(int i=1;i<=n;i++){
        assert(p[i]==i);
        //printf("%d ",p[i]);
    }
    //printf("\n");
}
/*
1 4 2 3
1 3 6 12
k(a+b) = a*b;
k*a+k*b = a*b;
b= (k*a)/(a-k);

k*(k+i)/i
*/