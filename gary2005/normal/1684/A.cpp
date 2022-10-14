/**
 *    author:  gary
 *    created: 19.05.2022 22:24:42
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
int f[100001];
void solve(){
    int n;
    cin>>n;
    if(n<=100000){
        cout<<f[n]<<endl;
        return ;
    }
    int mn=INF;
    while (n)
    {
        check_min(mn,n%10);
        n/=10;
    }
    cout<<mn<<endl;
}
int tonum(vector<int> v){
    reverse(ALL(v));
    int ans=0;
    for(auto it:v) ans*=10,ans+=it;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rb(i,1,100000){
        vector<int> digit;
        int now=i;
        while (now){
            digit.PB(now%10);
            now/=10;
        }
        assert(tonum(digit)==i);
        if(*min_element(ALL(digit))>0){
            if(i<10) f[i]=i;
            else{
                f[i]=INF;
                rep(j,digit.size()){
                    rep(k,j){
                        auto nw=digit;
                        swap(nw[j],nw[k]);
                        check_min(f[i],f[tonum(nw)/10]);
                    }
                }
            }
        }
    }
    while (t--)
    {
        solve();
    }
    return 0;
}