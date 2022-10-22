//2019.9.1 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define unl __int128
#define eps 5.6e-8
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define gc getchar
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
//inline int read() {
//    res s=0,ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
inline int read() {
    res s=0,ch=gc(),w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
//inline void write(RG unl x){
//    if(x>10)write(x/10);
//    putchar(int(x%10)+'0');
//}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
const int N=1e5+10;
namespace MAIN{
    int cl,ce,v;
    int L[N],E[N];
    inline int find(const res &I){
        res l=0,r=cl;
        while(l<=r){
            res mid=(l+r)>>1;
            if(L[mid]<=I&&I<L[mid+1])return mid;
            if(L[mid]<=I)l=mid+1;
            else r=mid-1;
        }
        return 0;
    }
    inline int Find(const res &I){
        res l=0,r=ce;
        while(l<=r){
            res mid=(l+r)>>1;
            if(E[mid]<=I&&I<E[mid+1])return mid;
            if(E[mid]<=I)l=mid+1;
            else r=mid-1;
        }
        return 0;
    }
    inline void MAIN(){
        read(),read(),cl=read(),ce=read(),v=read(),L[cl+1]=E[ce+1]=inf;
        for(res i=1;i<=cl;i++)L[i]=read();
        for(res i=1;i<=ce;i++)E[i]=read();
        res q=read();
        while(q--){
            res y1=read(),x1=read(),y2=read(),x2=read(),ans=inf;
            if(y1==y2){printf("%d\n",abs(x1-x2));continue;}
            res k=find(x1),j=Find(x1);
            if(j)ans=min(ans,abs(x1-E[j])+(abs(y2-y1)-1)/v+1+abs(E[j]-x2));
            if(j<ce)ans=min(ans,abs(x1-E[j+1])+(abs(y2-y1)-1)/v+1+abs(E[j+1]-x2));
            if(k)ans=min(ans,abs(x1-L[k])+abs(y2-y1)+abs(L[k]-x2));
            if(k<cl)ans=min(ans,abs(x1-L[k+1])+abs(y2-y1)+abs(L[k+1]-x2));
            printf("%d\n",ans);
        }
    }
}
int main(){
//    srand(19260817);
//    freopen("zao.in","r",stdin);
//    freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}