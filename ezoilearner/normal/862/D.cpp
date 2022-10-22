#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int ans0,ans1;
#define Maxn 1005
int vec[Maxn];

inline int query(){
    printf("? ");
    for(register int i=1;i<=n;++i)printf("%d",vec[i]);
    puts("");
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}

int Type0;
inline bool check0(int mid){
    for(register int i=1;i<=mid;++i)vec[i]=1;
    for(register int i=mid+1;i<=n;++i)vec[i]=0;
    if(query()==Type0-mid)return false;
    return true;
}
inline void solve0(){
    for(register int i=1;i<=n;++i)vec[i]=0;
    Type0=query();
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(check0(mid))r=mid;
        else l=mid+1;
    }
    ans0=l;
}

int Type1;
inline bool check1(int mid){
    for(register int i=1;i<=mid;++i)vec[i]=0;
    for(register int i=mid+1;i<=n;++i)vec[i]=1;
    if(query()==Type1-mid)return false;
    return true;
}
inline void solve1(){
    for(register int i=1;i<=n;++i)vec[i]=1;
    Type1=query();
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(check1(mid))r=mid;
        else l=mid+1;
    }
    ans1=l;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)vec[i]=0;
    int type0=query();
    vec[1]=1;
    for(int i=2;i<=n;++i)vec[i]=0;
    int type1=query();
    if(type0>type1){
        ans1=1;
        solve0();
    }else{
        ans0=1;
        solve1();
    }
    printf("! %d %d\n",ans0,ans1);
    fflush(stdout);
}