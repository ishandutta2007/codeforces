/**
 *    author:  gary
 *    created: 04.03.2022 23:34:38
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
vector<vector<int> > oper;
SRAND;
multiset<int> se[101];
multiset<int> full;
int n;
void doit(vector<int> v){
    oper.PB(vector<int> (0));
    rep(i,n){
        oper.back().PB(v[i]);
        se[i].erase(se[i].find(v[i]));
        se[(i+1)%n].insert(v[i]);
    }
}
void doit(deque<int> v){
    oper.PB(vector<int> (0));
    rep(i,n){
        oper.back().PB(v[i]);
        se[i].erase(se[i].find(v[i]));
        se[(i+1)%n].insert(v[i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rep(i,n) full.insert(i);
    rb(i,1,n){
        rb(j,1,n){
            int u;
            cin>>u;
            se[i-1].insert(u-1);
        }
    }
    while(true){
        bool ok=1;
        rep(i,n) ok&=se[i]==full;
        if(ok) break;
        vector<int> v(n,-1);
        rep(i,n) if(se[i]!=full){
            int pre=-1;
            for(auto ite=se[i].begin();ite!=se[i].end();ite++){
                if(*ite==pre){
                    pre=*ite;
                    break;
                }
                pre=*ite;
            }
            v[i]=pre;
        }
        rep(i,n){
            for(int j=(i+1)%n;v[j]==-1;(j+=1)%=n){
                v[j]=v[i];
            }
        }
        doit(v);
    }
    rb(i,1,n-1){
        deque<int> v;
        rep(j,n) v.PB((i+j)%n);
        rep(j,i){
            doit(v);
            int bk=v.back();
            v.pop_back();
            v.push_front(bk);
        }
    }
    cout<<oper.size()<<endl;
    for(auto it:oper){
        for(auto itt:it) cout<<itt+1<<" ";
        cout<<endl;
    }
    // rep(i,n){
    //     for(auto ite=se[i].begin();ite!=se[i].end();ite++){
    //         cout<<*ite<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}