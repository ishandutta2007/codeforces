/**
 *    author:  gary
 *    created: 06.06.2022 18:32:54
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
int ans=INF;
tuple<int,int,int> sol;
int c[3]={0,0,0};
void upd(int i,int j,int k){
    int f=abs(i*c[0]-j*c[1])+abs(j*c[1]-k*c[2]);
    if(f<ans){ans=f,sol={i,j,k};}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,s;
    cin>>n>>s;
    rb(i,1,n){
        int ai;
        cin>>ai;
        c[ai-3]++;
    }
    rb(i,0,s/c[0]){
        int rest=s-c[0]*i;
        int l=i,r=rest/(c[1]+c[2]);
        if(l>r) break;
        int tmp=rest%c[2];
        int j1=l;
        while(j1<=r&&j1*c[1]%c[2]!=tmp){
            j1++;
        }
        if(j1>r) continue;
        int j2=r;
        while (j2*c[1]%c[2]!=tmp){
            j2--;
        }
        if(j1==j2){
            int k=(rest-j1*c[1])/c[2];
            upd(i,j1,k);
        }
        else{
            int j3=j1+1;
            while (j3<=r&&j3*c[1]%c[2]!=tmp){
                j3++;
            }
            int d=j3-j1;
            int l=0,r=(j2-j1)/d+1;
            int L=l,R=r;
            while (l<r-1){
                int mid=(l+r)>>1;
                if(c[1]*(mid*d+j1)<=rest-c[1]*(mid*d+j1)) l=mid;
                else r=mid;
            }
            rb(x,max(L,l-50),min(R-1,l+50)) upd(i,j1+x*d,(rest-c[1]*(j1+x*d))/c[2]);
        }
    }
    if(ans==INF) cout<<-1<<endl;
    else cout<<get<0>(sol)<<" "<<get<1>(sol)<<" "<<get<2>(sol)<<endl;
    return 0;
}