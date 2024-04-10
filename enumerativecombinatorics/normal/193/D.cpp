#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000009;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-10;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int p[310000];
int rev[310000];
const int SQ=1000;
const int F=150000;
int now[310000];
short cur[310][301000];
int sq[1100];
void query(int a,int b,int c){
    int A=a/SQ+1;
    int B=b/SQ;
    if(A<=B){
        for(int i=a;i<A*SQ;i++){
            cur[i/SQ][F+now[i]]--;
            now[i]+=c;
            cur[i/SQ][F+now[i]]++;
        }
        for(int i=A;i<B;i++){
            sq[i]+=c;
        }
        for(int i=B*SQ;i<=b;i++){
            cur[i/SQ][F+now[i]]--;
            now[i]+=c;
            cur[i/SQ][F+now[i]]++;
        }
    }else{
        for(int i=a;i<=b;i++){
            cur[i/SQ][F+now[i]]--;
            now[i]+=c;
            cur[i/SQ][F+now[i]]++;
        }
    }
}
int count(){
    int ret=0;
    for(int i=0;i<310;i++){
        ret+=cur[i][F+1-sq[i]]+cur[i][F+2-sq[i]];
    }
    return ret;
}
int main(){
    int a;scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",p+i);p[i]--;
        rev[p[i]]=i;
    }
    long long ret=0;
    for(int i=0;i<a;i++)cur[i/SQ][F]++;
    for(int i=0;i<a;i++){
        int at=rev[i];
        int L=-1;
        int R=-1;
        if(at&&p[at-1]<i)L=p[at-1];
        if(at<a-1&&p[at+1]<i)R=p[at+1];
        if(L<R)swap(L,R);
        if(R>-1)query(0,R,-1);
        if(L>-1)query(R+1,L,0);
        query(L+1,i,1);
        ret+=count();
    }
    ret-=a;
    printf("%I64d\n",ret);
}