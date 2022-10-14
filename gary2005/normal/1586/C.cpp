/**
 *    author:  gary
 *    created: 17.10.2021 19:02:43
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
int n,m;
vector<char> mz[1000000+1]; 
vector<bool> have[1000000+1];
int ok[1000000+1];
bool bad[1000000+1];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rb(i,0,n) mz[i].resize(m+1);
    rb(i,0,n) have[i]=vector<bool> (m+1,0);
    rb(i,1,n) rb(j,1,m) cin>>mz[i][j];
    rb(j,1,m) mz[0][j]='.';
    rb(i,0,n-1) rb(j,2,m) have[i][j]=(mz[i][j]=='X'&&mz[i+1][j-1]=='X');
    rb(j,1,m){
        rb(i,0,n-1) ok[j]|=have[i][j];
        ok[j]+=ok[j-1];
        rb(i,2,n-1) bad[j]|=(mz[i][j]=='X');
    }
    int q;
    cin>>q;
    rb(i,1,q){
        int l,r;
        cin>>l>>r;
        if(ok[r]==ok[l]){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}