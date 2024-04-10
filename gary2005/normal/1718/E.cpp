/**
 *    author:  gary
 *    created: 01.09.2022 12:18:21
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+20;
int n,m,L[MAXN],R[MAXN],usedL[MAXN],p[MAXN],pos[MAXN];
bool f;
map<int,int> Lg[2][MAXN],Rg[2][MAXN];
vector<int> Ls[2][MAXN],Rs[2][MAXN];
bool equ(vector<int> &a,vector<int> &b){
    if(a.size()!=b.size()) return false;
    rep(i,a.size()) if(a[i]!=b[i]) return false;
    return true;
}
vector<int> paint;
bool Chk(int i,int j){
    auto x=(i<0? L[-i]:R[i]);
    if(x&&x!=j) return false;
    if(x) return true;
    paint.push_back(i);
    if(i<0) paint.push_back(j+INF),usedL[j]=1;
    if(i<0) L[-i]=j;
    else R[i]=j;
    if(i<0){
        if(!equ(Ls[0][j],Ls[1][-i])) return false;
        for(auto it:Lg[0][j]){
            if(!Chk(Lg[1][-i][it.first],it.second)) return false;
        }
    }
    else{
        if(!equ(Rs[0][j],Rs[1][i])) return false;
        for(auto it:Rg[0][j]){
            if(!Chk(-Rg[1][i][it.first],it.second)) return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    if(n>m){
        f=1;
        rb(i,1,n){
            rb(j,1,m){
                int x;
                cin>>x;
                if(x) {Lg[0][j][x]=i;Rg[0][i][x]=j;Ls[0][j].push_back(x);Rs[0][i].push_back(x);}
            }
        }
        rb(i,1,n){
            rb(j,1,m){
                int x;
                cin>>x;
                if(x) {Lg[1][j][x]=i;Rg[1][i][x]=j;Ls[1][j].push_back(x);Rs[1][i].push_back(x);}
            }
        }
        swap(n,m);
    }
    else{
        rb(i,1,n){
            rb(j,1,m){
                int x;
                cin>>x;
                if(x) {Lg[0][i][x]=j;Rg[0][j][x]=i;Ls[0][i].push_back(x);Rs[0][j].push_back(x);}
            }
        }
        rb(i,1,n){
            rb(j,1,m){
                int x;
                cin>>x;
                if(x) {Lg[1][i][x]=j;Rg[1][j][x]=i;Ls[1][i].push_back(x);Rs[1][j].push_back(x);}
            }
        }
    }
    rb(i,1,n) L[i]=0,sort(ALL(Ls[0][i])),sort(ALL(Ls[1][i]));
    rb(i,1,m) R[i]=0,sort(ALL(Rs[0][i])),sort(ALL(Rs[1][i]));
    rb(i,1,n){
        if(!L[i]){
            bool ok=0;
            rb(j,1,n){
                if(!usedL[j]){
                    paint.clear();
                    if(Chk(-i,j)){
                        ok=1;
                        break;
                    }
                    for(auto it:paint){
                        if(it>=INF) usedL[it-INF]=0;
                        else if(it<0) L[-it]=0;
                        else R[it]=0;
                    }
                }
            }
            if(!ok){
                cout<<"-1\n";
                return 0;
            }
        }
    }
    set<int> not_used;
    rb(i,1,m) not_used.insert(i);
    rb(i,1,m) if(R[i]) not_used.erase(R[i]);
    rb(i,1,m) if(!R[i]) R[i]=*not_used.begin(),not_used.erase(not_used.begin());
    vector<tuple<int,int,int> > ans;
    // rb(i,1,n){
    //     cout<<L[i]<<' ';
    // }
    // cout<<endl;
    // rb(i,1,m){
    //     cout<<R[i]<<' ';
    // }
    // cout<<endl;
    rb(i,1,n) pos[i]=p[i]=i;
    rb(i,1,n) if(p[i]!=L[i]) ans.push_back({1,i,pos[L[i]]}),swap(p[i],p[pos[L[i]]]),swap(pos[p[i]],pos[p[pos[L[i]]]]);
    rb(i,1,m) pos[i]=p[i]=i;
    rb(i,1,m) if(p[i]!=R[i]) ans.push_back({2,i,pos[R[i]]}),swap(p[i],p[pos[R[i]]]),swap(pos[p[i]],pos[p[pos[R[i]]]]);
    cout<<ans.size()<<'\n';
    for(auto &[t,x,y]:ans){
        if(f) t=((t-1)^1)+1;
        cout<<t<<' '<<x<<" "<<y<<'\n';
    }
    return 0;
}