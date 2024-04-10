#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
string s[10];
int k; 
void move(int val){
    cout<<"next ";
    rep(i,0,10) if((val>>i)&1) cout<<i<<" ";
    cout<<endl;
    cin>>k;
    rep(i,0,k) cin>>s[i];
    if(k==1){
        cout<<"done"<<endl;
        exit(0);
    }
}
signed main(){
    while(1){
        move(1);
        move(3);
        bool done=0;
        rep(i,0,k){
            bool f1=0,f0=0;
            rep(j,0,sz(s[i])){
                if(s[i][j]=='0') f0=1;
                if(s[i][j]=='1') f1=1;
            }
            if(f0 and f1){
                done=1;
                break;
            }
        }
        if(done) break;
    }
    while(1) move((1<<10)-1);
    return 0;
}