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

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

long long int INF = 1e18;
long long int mod = 998244353;
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
char dir[] = "RULD";
//,,,

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<x;
#define re(i,n) for(i=0;i<n;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl

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
        swap(number1 , number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1 , number1);
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

ll i,j,k,ii,jj,n,m,a,b,c,d,e,f,g,h,r,w,l,num,sum,ans,ok,ng,mid;
ll x[1000005],y[500005],z[500005];
ll dp[5050][5005];
bool used[5005][5005];
char s[500005],t[500005],u[500005];
bool dame,flag;
//string s;

ll solve(ll l,ll r){
	if(used[l][r]){
		return dp[l][r];
	}
	used[l][r] = 1;
	ll ans;
	if(l == r){
		ans = 0;
		dp[l][r] = ans;
		return 0;
	}else if(x[l] == x[r]){
		//p("!");
		ans = solve(l+1,r-1) + 1;
		dp[l][r] = ans;
		return ans;
	}else{
		ll a,b;
		a = 1 + solve(l+1,r);
		b = 1 + solve(l,r-1);
		ans = min(a,b);
		dp[l][r] = ans;
		return ans;
	}
}

int main(){
	cin >> n;
	b = INF;
	num = 1;
	for(i=0;i<n;i++){
		cin >> a;
		if(a == b){
			continue;
		}else{
			x[num++] = a;
		}
		b = a;
	}
	n = num - 1;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			//pe(i);pe(j);p(solve(i,j));
		}
		//el;
	}

	p(solve(1,n));
	return 0;
}