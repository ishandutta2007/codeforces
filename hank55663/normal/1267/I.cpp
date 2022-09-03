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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
int q[205][205];
int query(int x,int y){
    if(q[x][y]==-1){
        printf("? %d %d\n",x,y);
        fflush(stdout);
        char c;
        scanf(" %c",&c);
        if(c=='>')q[x][y]=1;
        else q[x][y]=0;
    }
    return q[x][y];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        MEMS(q);
        int n;
        scanf("%d",&n);
        vector<int> v;
        v.pb(1);
        v.pb(2);
        v.pb(3);
        v.pb(4);
        if(!query(1,3)){
            swap(v[0],v[2]);
        }
        if(!query(2,4)){
            swap(v[1],v[3]);
        }
        if(!query(v[2],v[3])){
            swap(v[0],v[1]);
            swap(v[2],v[3]);
        }
        for(int i = 5;i<=2*n;i++){
            v.pop_back();
            v.pb(i);
            if(!query(v[1],v[3]))
                swap(v[1],v[3]);
            if(!query(v[2],v[3])){
                swap(v[0],v[1]);
                swap(v[2],v[3]);
                //printf("?\n");
              // v.pop_back();
            }
        }
        for(int i=1;i<=2*n;i++)
            for(int j=1;j<=2*n;j++){
                if(i!=v[0]&&i!=v[1]&&j!=v[0]&&j!=v[1]&&i!=j)
                    query(i,j);
            }
        printf("!\n");
fflush(stdout);
    }
}