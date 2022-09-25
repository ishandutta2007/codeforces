#include <cstdio>
#include <algorithm>
#include <chrono>
#include <unordered_map>
#include <utility>
#include <cstring>
#include <unordered_set>
using namespace std;
typedef pair<int,int> ii;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(const pair<int,int> &i)const{
        return ((long long)i.first)|(((long long)i.second)<<32);
    }
};
int n;
unordered_map<long long,int, custom_hash> box;

ii bmask[40005][21];
long long val[20];

int main(){
    scanf("%d",&n);
    int k,t;
    long long goal=0;
    for (int x=0;x<n;x++){
        scanf("%d",&k);
        while (k--){
            scanf("%d",&t);
            box[t]=x;
            goal+=t;
            val[x]+=t;
        }
    }

    if (goal%n!=0){
        printf("NO\n");
        return 0;
    }
    goal/=n;

    ii curr[20];

    long long rn;
    long long nxt;
    int mask;

    for (unordered_map<long long,int,custom_hash>::iterator it=box.begin();it!=box.end();it++){
        memset(curr,-1,sizeof(curr));
        mask=0;

        rn=it->first;
        nxt=goal-(val[box[rn]]-rn);
        if (box.count(nxt)==0) goto _die;
        if (mask&(1<<box[nxt])) goto _die;
        curr[box[nxt]]=ii(nxt,box[rn]);
        rn=nxt;
        mask|=(1<<box[rn]);
        while (rn!=it->first){
            nxt=goal-(val[box[rn]]-rn);
            if (box.count(nxt)==0) goto _die;
            if (mask&(1<<box[nxt])) goto _die;
            curr[box[nxt]]=ii(nxt,box[rn]);
            rn=nxt;
            mask|=(1<<box[rn]);
        }

        bmask[mask][20]=ii(69,69);
        for (int x=0;x<20;x++) bmask[mask][x]=curr[x];

        _die:;
    }

    for (int x=0;x<(1<<n);x++){
        if (bmask[x][20]==ii(69,69)) continue;
        for (int s=x;s;s=((s-1)&x)){
            if (bmask[s][20]==ii(69,69) && bmask[s^x][20]==ii(69,69)){
                for (int it=0;it<=20;it++){
                    if (bmask[s][it]!=ii(-1,-1)) bmask[x][it]=bmask[s][it];
                    if (bmask[s^x][it]!=ii(-1,-1)) bmask[x][it]=bmask[s^x][it];
                }
                break;
            }
        }
    }

    if (bmask[(1<<n)-1][20]!=ii(69,69)) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for (int x=0;x<n;x++){
        printf("%d %d\n",bmask[(1<<n)-1][x].first,bmask[(1<<n)-1][x].second+1);
    }
}