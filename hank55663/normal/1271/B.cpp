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
#define MXN 200005
int main(){
    int n;
    scanf("%d",&n);
    char c[205];
    scanf("%s",c);
    int w=0,b=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='W')w++;
        if(c[i]=='B')b++;
    }
    if(w%2==0){
        int a[205];
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='W')a[i]=1;
            else a[i]=0;
        }
        vector<int> v;
        for(int i = 0;i<n-1;i++){
            if(a[i]){
                v.pb(i+1);
                a[i]^=1;
                a[i+1]^=1;
            }
        }
        assert(a[n-1]==0);
        printf("%d\n",v.size());
        for(auto it:v)
            printf("%d ",it);
        printf("\n");
    }
    else if(b%2==0){
        int a[205];
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='B')a[i]=1;
            else a[i]=0;
        }
        vector<int> v;
        for(int i = 0;i<n-1;i++){
            if(a[i]){
                v.pb(i+1);
                a[i]^=1;
                a[i+1]^=1;
            }
        }
        assert(a[n-1]==0);
        printf("%d\n",v.size());
        for(auto it:v)
            printf("%d ",it);
        printf("\n");
    }
    else{
        printf("-1\n");
    }
}