#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0) 
map<int,int> f;
map<int,int> value;
pii Find(int x){
    //printf("%d\n",x);
    if(f[x]==x)return mp(x,value[x]);
    pii p=Find(f[x]);
    f[x]=p.x;
    value[x]^=p.y;
    return mp(f[x],value[x]);
}
int main(){
    int q;
    scanf("%d",&q);
    int last=0;
    while(q--){
        int t;
        scanf("%d",&t);
        if(t==1){
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            l^=last;
            r^=last;
            x^=last;
            if(l>r)
            swap(l,r);
            l--;
            //printf("%d %d %d\n",l,r,x);
            if(f.find(l)==f.end()){
                f[l]=l;
                value[l]=0;
            }
            if(f.find(r)==f.end()){
                f[r]=r;
                value[r]=0;
            }
            pii p1=Find(l);
            pii p2=Find(r);
            if(p1.x!=p2.x){
                x^=p2.y;
                x^=p1.y;
                f[p2.x]=p1.x;
                value[p2.x]=x;
            }
        }
        else{
            int l,r;
            scanf("%d %d",&l,&r);
            l^=last;
            r^=last;
            if(l>r)
            swap(l,r);
            l--;
            //printf("%d %d\n",l,r);
            if(f.find(l)==f.end()||f.find(r)==f.end()){
                printf("-1\n");
                last=1;
                continue;
            }
            pii p1=Find(l),p2=Find(r);
            if(p1.x!=p2.x){
                printf("-1\n");
                last=1;
            }
            else{
                printf("%d\n",p2.y^p1.y);
                last=p2.y^p1.y;
            }
        }
    }
}