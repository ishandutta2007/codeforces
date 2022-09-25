#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int pre[400005][21];
int n;
long long w[1050000];
long long memo[25][25];
long long total[25];
vector<int> pos[25];
int main(){
    scanf("%d",&n);
    int t;
    for (int x=0;x<n;x++){
        if (x) for (int y=0;y<20;y++) pre[x][y]=pre[x-1][y];
        scanf("%d",&t);
        t--;
        pre[x][t]++;
        pos[t].push_back(x);
    }
    for (int x=0;x<20;x++){
        for (int it=0;it<pos[x].size();it++){
            for (int y=0;y<20;y++){
                memo[x][y]+=pre[pos[x][it]][y];
            }
            total[x]+=pos[x][it]-it;
        }
    }
    memset(w,127,sizeof(w));
    w[0]=0;
    int bm,bm2;
    int flipped=(1<<20)-1;
    int bit;
    long long store;
    for (int x=0;x<flipped;x++){
        bm=flipped^x;
        while (bm){
            bit=__builtin_ctz(bm);
            store=w[x];
            store+=total[bit];
            bm2=x;
            while (bm2){
                store-=memo[bit][__builtin_ctz(bm2)];
                bm2^=bm2&-bm2;
            }
            w[x^(1<<bit)]=min(w[x^(1<<bit)],store);
            bm^=bm&-bm;
        }
    }
    printf("%lld\n",w[flipped]);
}