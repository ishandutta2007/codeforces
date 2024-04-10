/**
 *    author:  gary
 *    created: 24.03.2022 22:31:43
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        LL n;
        cin>>n;
        __int128_t k=1;
        LL tmp=n;
        while (n%2==0)
        {
            k<<=1;
            n>>=1;
        }
        k<<=1;
        if(k*(k+1)/2<=tmp){
            cout<<(LL)(k)<<endl;
        }
        else{
            k=n;
            if(k*(k+1)/2<=tmp&&k!=1){
                cout<<(LL)(k)<<endl;
            }
            else
            cout<<-1<<endl;
        }
    }
    return 0;
}