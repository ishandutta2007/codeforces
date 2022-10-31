#include <iostream>
#include <cassert>
#include <climits>
#include <bitset>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <tuple>
#include <time.h>
#include <random>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

long long int INF = 3e18;
double Pi = 3.1415926535897932384626;

vector<ll> G[500005];
//vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//ll bit[500005];
//,,,


#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound


ll mod = 1000000007;
ll rui(ll number1,ll number2){

    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll gcd(ll number1,ll number2){

    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }
}
void YES(bool condition){

    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){

    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}
void Yay(bool condition){

    if(condition){
        p("Yay!");
    }else{
        p(":(");
    }
    return;
}

//ll fact[800005],rfact[800005];
/*
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=800000; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
	rfact[800000] = rui(fact[800000],mod - 2);
	for(ll i=800000; i>=1; i--){
	   rfact[i-1] = rfact[i] * i;
	   rfact[i-1] %= mod;
	}
	return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod) * rfact[n-r]) % mod;}
*/

ll n,m,num,sum,ans,a,b,c,d,e,g,h,w,i,j,k,q;
ll x[100005],y[100005],z[100005];
ll dp[500005][30];
ll need[30];
char s[500005],t[500005];

void init_T(){
    for(int i=0;i<26;i++){
        need[i] = 0;
    }
    for(int i=0;i<m;i++){
        ll idx = t[i] - 'a';
        need[idx]++;
    }
}

void init(){
    for(i=0;i<n;i++){
        for(j=0;j<26;j++){
            if(s[i] == 'a' + j){
                dp[i+1][j] = dp[i][j] + 1;
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    return;
}


bool check(ll idx){
    //sidx
    bool ok = true;
    for(int i=0;i<26;i++){
        if(need[i] > dp[idx][i])ok = false;
    }
    return ok;
}



int main(){
	cin >> n;
    cin >> s;
    cin >> k;
    init();
    //dp[i][j] := si
    for(i=0;i<k;i++){
        cin >> t;
        
        m = strlen(t);
        init_T();
        ll ok = n,ng = 0;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;
            bool isok = check(mid);
            if(isok){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        p(ok);
    }
    

	return 0;
}