/**
 *    author:  gary
 *    created: 11.12.2021 17:56:02
**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
const int MAXN=100000+20;
int n;
int x[MAXN],y[MAXN],c[MAXN];
int cnt[MAXN][4];
int answer=0;
int id[MAXN];
bool cmp(int A,int B){
    return x[A]<x[B];
}
bool check(int _){
    int a[3]={1,2,3};
    do{
        int c=0;
        int p,pv;
        p=0;
        pv=-INF;
        rb(i_,1,n){
            int i=id[i_];
            if(x[i]==pv){
                p=i_;
                continue;
            }
            if(cnt[i_][a[c]]-cnt[p][a[c]]>=_){
                c++;
                p=i_;
                pv=x[i];
                if(c==3) break;
            }
        }
        if(c==3) return 1;
    }while(next_permutation(a,a+3));
    return false;
}
void solve1(){
    memset(cnt,0,sizeof(cnt));
    rb(i,1,n) id[i]=i;
    sort(id+1,id+1+n,cmp);
    rb(i,1,n) {
        rb(j,1,3) cnt[i][j]=cnt[i-1][j];
        cnt[i][c[id[i]]]++;
    }
    int l=0,r=n/3+1;
    while(l<r-1){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid;
        }
        else r=mid;
    }
    check_max(answer,l);
}
void solve2(int A,int B,int C){
    tree<mp, null_type, less<mp>, rb_tree_tag, tree_order_statistics_node_update> tb,tc;
    int r=0;
    rb(i,1,n) {
        rb(j,1,3) cnt[i][j]=cnt[i-1][j];
        cnt[i][c[id[i]]]++;
    }
    rl(i_,n,1){
        while(r<tb.size()&&r<tc.size()){
            r++;
            auto ite=tb.find_by_order(r-1);
            auto ite2=tc.find_by_order(tc.size()-r);
            if(ite->FIR<ite2->FIR);
            else{
                r--;
                break;
            }
        }
        if(i_==n||x[id[i_]]!=x[id[i_+1]]){
            check_max(answer,min(r,cnt[i_][A]));
        }
        int i=id[i_];
        if(c[i]==B) tb.insert(II(y[i],i));
        if(c[i]==C) tc.insert(II(y[i],i));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    map<int,int> lx,ly;
    rb(i,1,n) cin>>x[i]>>y[i]>>c[i],lx[x[i]]=ly[y[i]]=1;
    int cnt=0;
    for(auto ite=lx.begin();ite!=lx.end();ite++){
        ite->SEC=++cnt;
    }
    cnt=0;
    for(auto ite=ly.begin();ite!=ly.end();ite++){
        ite->SEC=++cnt;
    }
    rb(i,1,n) x[i]=lx[x[i]],y[i]=ly[y[i]];
    solve1();
    solve2(1,2,3);
    solve2(1,3,2);
    solve2(2,1,3);
    solve2(2,3,1);
    solve2(3,1,2);
    solve2(3,2,1);
    reverse(id+1,id+1+n);
    solve2(1,2,3);
    solve2(1,3,2);
    solve2(2,1,3);
    solve2(2,3,1);
    solve2(3,1,2);
    solve2(3,2,1);
    rb(i,1,n) swap(x[i],y[i]);
    solve1();
    solve2(1,2,3);
    solve2(1,3,2);
    solve2(2,1,3);
    solve2(2,3,1);
    solve2(3,1,2);
    solve2(3,2,1);
    reverse(id+1,id+1+n);
    solve2(1,2,3);
    solve2(1,3,2);
    solve2(2,1,3);
    solve2(2,3,1);
    solve2(3,1,2);
    solve2(3,2,1);
    cout<<answer*3<<endl;
    return 0;
}