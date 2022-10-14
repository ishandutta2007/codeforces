/**
 *    author:  gary
 *    created: 05.08.2022 16:06:22
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
mp z[4]={{1,1},{1,2},{1,3},{1,4}},o[2]={{4,1},{4,3}};
bool zz[4],oo[2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    for(auto it:s){
        if(it=='0'){
            rep(j,4){
                if(!zz[j]){
                    cout<<z[j].first<<" "<<z[j].second<<endl;
                    zz[j]=1;
                    break;
                }
            }
        }
        else{
            rep(j,2){
                if(!oo[j]){
                    cout<<o[j].first<<" "<<o[j].second<<endl;
                    oo[j]=1;
                    break;
                }
            }
        }
        if(*min_element(zz,zz+4)==1) rep(i,4) zz[i]=0;
        if(*min_element(oo,oo+2)==1) rep(i,2) oo[i]=0;
    }
    return 0;
}