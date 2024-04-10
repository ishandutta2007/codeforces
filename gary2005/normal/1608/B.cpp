/**
 *    author:  gary
 *    created: 11.12.2021 17:55:42
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
int tmp[100000+20];
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    if(abs(a-b)>1||a+b>n-2) cout<<-1<<endl;
    else{
        if(a==b+1){
            int now=1;
            rb(i,1,a) tmp[now++]=1,tmp[now++]=-1;
            rb(i,now,n) tmp[i]=-1;
        }
        if(a==b){
            int now=1;
            tmp[now++]=1;
            rb(i,1,b)  tmp[now++]=-1,tmp[now++]=1;
            rb(i,now,n) tmp[i]=1;
        }
        if(a==b-1){
            int now=1;
            rb(i,1,b) tmp[now++]=-1,tmp[now++]=1;
            rb(i,now,n) tmp[i]=1;
        }
        int l,r;
        l=1,r=n;
        rb(i,1,n){
            if(tmp[i]==1) cout<<(l++);
            else cout<<(r--);
            cout<<" ";
        }
        cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}