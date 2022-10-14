/**
 *    author:  gary
 *    created: 21.04.2022 11:10:52
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
    int n;
    cin>>n;
    int k=(2*n+1)/3;
    cout<<k<<endl;
    if(n%3==0){
        cout<<n<<' '<<1<<endl;
        k--;
        rb(i,1,(k+1)/2){
            cout<<i<<" "<<(k+1)/2-i+1+1<<endl;
        }
        rb(i,1,k/2){
            cout<<n-1-i+1<<" "<<n-(k/2)+i<<endl;
        }
    }
    else{
        rb(i,1,(k+1)/2){
            cout<<i<<" "<<(k+1)/2-i+1<<endl;
        }
        rb(i,1,k/2){
            cout<<n-i+1<<" "<<n-(k/2)+i<<endl;
        }
    }
    return 0;
}