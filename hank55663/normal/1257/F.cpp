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
#define MXN 300000
#define N 100005
#define hash Hash
int main(){
    int n;
    scanf("%d",&n);
    int a[105];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    map<vector<int>,int> m;
    for(int i = 0;i<(1<<15);i++){
        vector<int> tmp;
        for(int j=0;j<n;j++){
            tmp.pb(__builtin_popcount((i^a[j])%(1<<15)));
        }
        m[tmp]=i;
    }
    for(int i = 0;i<(1<<15);i++){
        vector<int> tmp;
        for(int j=0;j<n;j++){
            tmp.pb(-__builtin_popcount((i^(a[j]>>15))));
        }
        for(int j=0;j<50;j++){
            if(m.find(tmp)!=m.end()){
                printf("%d\n",(i<<15)+m[tmp]);
                return 0;
            }
            for(auto &it:tmp){
                it++;
            }
        }
    }
    printf("-1\n");
}