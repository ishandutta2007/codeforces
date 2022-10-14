/**
 *    author:  gary
 *    created: 05.08.2022 15:29:14
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
bool query(int x,int y){
    cout<<"? "<<x<<" "<<y<<'\n';ff;
    char c;
    cin>>c;
    if(c=='e') exit(0);
    return c=='y';
}
void solve(int l,int r){
    check_max(l,2);
    if(query(l,1)){
        cout<<"! "<<l<<endl;
        return;
    }
    int L=l+1,R=r;
    while (L<R){
        int mid=(L+R)>>1;
        if(!query(l,mid)) R=mid;
        else L=mid+1;
    }
    cout<<"! "<<L<<endl;
    return ;
}
int main(){
    while (true){
        string s;
        cin>>s;
        if(s=="mistake") break;
        if(s=="end") break;
        if(!query(1,2)&&!query(2,1)){
            cout<<"! "<<1<<endl;
            ff;
            continue;
        }
        int f=1;
        // a>=f
        while (true){
            if(2*f>1e9) {solve(f,1e9);break;}
            if(!query(f,2*f)) {solve(f,2*f);break;}
            f<<=1;
        }
        ff;
    }
    return 0;
}