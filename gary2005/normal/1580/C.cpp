/**
 *    author:  gary
 *    created: 30.09.2021 18:03:40
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAGIC=450;
int n,m;
int a[200000+1],x[200000+1],y[200000+1],rest[200000+1],cf[200000+1],cf2[200000+1];
int tmp[MAGIC][MAGIC],pt[MAGIC],is[200000+1],tim[200000+1],addi;
int main(){
    cin>>n>>m;
    rb(i,1,n){
        scanf("%d%d",&x[i],&y[i]);
    }
    rb(_,1,m){
        int op;
        int t;
        scanf("%d%d",&op,&t);
        rb(i,1,MAGIC-1){
            pt[i]++;
            pt[i]%=i;
        }
        if(op==1){
            tim[t]=_;
            int len=x[t]+y[t];
            if(x[t]+y[t]<MAGIC){
                is[t]=pt[len];
                rep(j,len){
                    tmp[len][(pt[len]+j)%len]+=(j<x[t]? 0:1);
                }
            }
            else{
                for(int i=_;i<=m;i+=len){
                    if(i+x[t]<=m) cf[i+x[t]]++;
                    if(i+len<=m) cf[i+len]--;
                }
            }
        }
        if(op==2){
            int len=x[t]+y[t];
            if(x[t]+y[t]<MAGIC){
                rep(j,len){
                    tmp[len][(is[t]+j)%len]-=(j<x[t]? 0:1);
                }
            }
            else{
                for(int i=tim[t];i<=m;i+=len){
                    if(i+len<=_) continue;
                    if(i+x[t]<=m) cf2[max(_,i+x[t])]++;
                    if(i+len<=m) cf2[i+len]--;
                }
            }
        }
        cf2[_]+=cf2[_-1];
        cf[_]+=cf[_-1];
        addi=0;
        rb(i,1,MAGIC-1){
            addi+=tmp[i][pt[i]];
        }
        printf("%d\n",rest[_]+cf[_]-cf2[_]+addi);
    }
    return 0;
}