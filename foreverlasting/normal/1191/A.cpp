//2019.7.12 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define eps 5.6e-8
#define RG register
#define db long double
#define pc(x) __builtin_popcount(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define gc getchar
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
inline int read() {
    res s=0,ch=gc();
    while(ch<'0'||ch>'9')ch=gc();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s;
}
//inline int read() {
//    res s=0,ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
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
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace MAIN{
    int n;
    int p[4]={1,3,2,0};
    inline char get(const res &n){
        if(n%4==1)return 'A';
        if(n%4==2)return 'C';
        if(n%4==3)return 'B';
        return 'D';
    }
    inline bool cmp(const res &x,const res &y){
        res X,Y;
        for(res i=0;i<4;i++)if(x==p[i])X=i;
        for(res i=0;i<4;i++)if(y==p[i])Y=i;
        return X>Y;
    }
    inline void MAIN(){
        n=read()%4;
        int t[5];
        t[0]=n,t[1]=(n+1)%4,t[2]=(n+2)%4;
        sort(t,t+3,cmp);
        if(t[2]==n){
            printf("%d %c\n",0,get(t[2]));
        }
        else if(t[2]==(n+1)%4){
            printf("%d %c\n",1,get(t[2]));
        }
        else printf("%d %c\n",2,get(t[2]));
    }
}
int main() {
//    srand((unsigned)time(NULL));
    // freopen("zao.in","r",stdin);
    // freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}