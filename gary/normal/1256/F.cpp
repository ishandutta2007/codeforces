/**
 *    author:  gary
 *    created: 01.10.2021 13:48:52
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
int n;
string s,t;
vector<int> pos[26];
int pt[26];
bool bit[MAXN];
int A[MAXN];
void add(int pos){
    while(pos<=n){
        bit[pos]^=1;
        pos+=pos&-pos;
    }
}
bool query(int pos){
    bool s=0;
    while(pos){
        s^=bit[pos];
        pos-=pos&-pos;
    }
    return s;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        cin>>n;
        rb(i,1,n) bit[i]=0;
        cin>>s>>t;
        rep(i,26) pos[i].clear(),pt[i]=0;
        rep(i,n) pos[t[i]-'a'].PB(i+1);
        bool noans=0;
        rb(i,1,n){
            int c=s[i-1]-'a';
            if(pt[c]==pos[c].size()){
                noans=1;
                break;
            }
            A[i]=pos[c][pt[c]++];
        }
        if(noans){
            cout<<"NO"<<endl;
            continue;
        }
        bool cnt=0;
        rb(i,1,n) cnt^=((i-1)&1)^query(A[i]),add(A[i]);
        if(cnt==0);
        else{
            noans=1;
            rep(i,26){
                if(pos[i].size()>=2){
                    noans=0;
                    break;
                }
            }
        }
        if(noans) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}