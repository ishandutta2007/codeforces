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

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

long long int INF = 3e18;
double Pi = 3.1415926535897932384626;

vector<ll> G[500005];
vector<P> tree[500010];
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
#define pd(x) cerr<<"//"<<(x)<<endl;
#define re(i,n) for(i=0;i<n;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl


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

ll n,m,num,sum,ans,a,b,c,d,e,g,h,w,i,j,k,l,q;
ll x[500005],y[500005],z[500005];
ll dp[5][500005];
char s[500005],t[500005];
bool flag,dame;

ll  fact[400005];
ll rfact[400005];

void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<400000; i++){
        fact[i] = (fact[i-1]*i) % mod;
        rfact[i] = rui(fact[i],mod - 2);
    }
}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod) * rfact[n-r]) % mod;
}

int main(){
	cin >> n;
	cin >> s >> t;
	for(i=0;i<n;i++){
		if(s[i] == '?'){
			G[30].pb(i);
		}else{
			G[s[i] - 'a'].pb(i);
		}
	}
	for(i=0;i<n;i++){
		if(t[i] == '?'){
			G[45].pb(i);
		}else if(G[t[i] - 'a'].size() > 0){
			a = G[t[i] - 'a'].back();
			G[t[i] - 'a'].pop_back();
			x[num] = i+1;
			y[num] = a+1;
			num++;
		}else if(G[30].size() > 0){
			a = G[30].back();
			G[30].pop_back();
			x[num] = i+1;
			y[num] = a+1;
			num++;
		}
	}
	for(i=0;i<26;i++){
		if(G[45].size() == 0)break;
		while(G[i].size() > 0 && G[45].size() > 0){
			//p("!");
			a = G[i].back();
			x[num] = G[45].back() + 1;
			y[num] = a + 1;
			num++;
			G[i].pop_back();
			G[45].pop_back();
		}
	}
	while(G[45].size() > 0 && G[30].size() > 0){
		y[num] = G[30].back() + 1;
		x[num] = G[45].back() + 1;
		num ++;
		G[30].pop_back();
		G[45].pop_back();
	}
	p(num);
	for(i=0;i<num;i++){
		pe(y[i]);p(x[i]);
	}
	return 0;
}