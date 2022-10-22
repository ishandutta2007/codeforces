/**
 *    author:  gary
 *    created: 25.09.2021 14:44:03
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
const int MAXN=2e5+1;
int n,m,a[MAXN],pre1[MAXN],pre2[MAXN],bit[500000];
void add(int pos,int val){
    while(pos<500000){
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}
int query(int pos){
    int s=0;
    while(pos){
        s+=bit[pos];
        pos-=pos&-pos;
    }
    return s;
}
LL answer=0;
void cdq(int l,int r){
    if(l>=r){
        return ;
    }
    int mid=(l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    vector<mp> A,B;
    rb(i,l,mid) A.PB(II(pre1[i],pre2[i]));
    rb(i,mid+1,r) B.PB(II(pre1[i],pre2[i]));
    sort(ALL(A)),sort(ALL(B));
    int pt=0;
    for(auto it:B){
        while(pt<A.size()&&A[pt].FIR<=it.FIR){
            add(A[pt].SEC,1);
            pt++;
        }
        answer+=query(it.SEC-1);
    }
    rep(i,pt) add(A[i].SEC,-1);
}
int main(){
    cin>>n>>m;
    rb(i,1,n) scanf("%d",&a[i]);
    pre1[0]=pre2[0]=n+1;
    rb(i,1,n) pre1[i]=(a[i]<=m? 1:-1),pre2[i]=(a[i]>=m? 1:-1),pre1[i]+=pre1[i-1],pre2[i]+=pre2[i-1];
    cdq(0,n);
    cout<<answer<<endl;
    return 0;
}