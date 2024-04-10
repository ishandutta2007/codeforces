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
    char A[3],B[3],C[3];
    inline void MAIN(){
        scanf("%s",A+1),scanf("%s",B+1),scanf("%s",C+1);
        if(A[1]==B[1]&&A[1]==C[1]&&A[2]==B[2]&&A[2]==C[2])puts("0");
        else {
            if(A[2]==B[2]&&A[2]==C[2]){
                int t[3];
                t[0]=A[1]-'0',t[1]=B[1]-'0',t[2]=C[1]-'0';
                sort(t,t+3);
                if(t[0]==t[1]-1&&t[1]==t[2]-1)puts("0");
                else {
                    if(t[0]==t[1]-1||t[1]==t[2]-1||t[0]==t[2]-1||t[0]==t[1]-2||t[0]==t[2]-2||t[1]==t[2]-2||t[0]==t[1]||t[1]==t[2])puts("1");
                    else puts("2");
                }
            }
            else {
                if(A[2]==B[2]){
                    if(A[1]>B[1])swap(A,B);
                    if(A[1]==B[1]-1||A[1]==B[1])puts("1");
                    else if(A[1]==B[1]-2)puts("1");
                    else puts("2");
                }
                else if(A[2]==C[2]){
                    if(A[1]>C[1])swap(A,C);
                    if(A[1]==C[1]-1||A[1]==C[1])puts("1");
                    else if(A[1]==C[1]-2)puts("1");
                    else puts("2");
                }
                else if(B[2]==C[2]){
                    if(B[1]>C[1])swap(B,C);
                    if(B[1]==C[1]-1||B[1]==C[1])puts("1");
                    else if(B[1]==C[1]-2)puts("1");
                    else puts("2");
                }
                else puts("2");
            }
        }
    }
}
int main() {
//    srand((unsigned)time(NULL));
    // freopen("zao.in","r",stdin);
    // freopen("std.out","w",stdout);
    MAIN::MAIN();
    return 0;
}