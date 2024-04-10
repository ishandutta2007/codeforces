#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n,q;
int nxt[500005];
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        return splitmix64(x);
    }
    size_t operator()(const pair<int,int> &i)const{
        return ((long long)i.first)|(((long long)i.second)<<32);
    }
};
unordered_map<int,int, custom_hash> m;
int ST[500005][20];
void buildST(){ //build sparse table
    for (int x=0;x<n;x++){
        ST[x][0]=nxt[x];
    }
    int j=1,logj=1;
    while (j<=(n>>1)){
        for (int x=0;x<=(n-(j<<1));x++){
            ST[x][logj]=min(ST[x][logj-1],ST[x+j][logj-1]);
        }
        j<<=1;
        logj++;
    }
}
int min_query(int i, int j){ ///in range [i,j]
    j=j-i+1;
    int row=31-__builtin_clz(j);
    j-=1<<row;
    return min(ST[i][row],ST[i+j][row]);
}
int main(){
    scanf("%d%d",&n,&q);
    int t;
    for (int x=0;x<n;x++){
        scanf("%d",&t);
        nxt[x]=1000000000;
        if (m.count(t)) nxt[m[t]]=x-m[t];
        m[t]=x;
    }

    buildST();

    int a,b;
    int ans;
    while (q--){
        scanf("%d%d",&a,&b);
        a--,b--;
        ans=0;
        while (a<=b){
            t=min_query(a,b);
            if (t>ans) b-=(t-ans),ans=t;
            else {
                printf("%d\n",ans);
                goto done;
            }
        }
        printf("-1\n");
        done:;
    }
}