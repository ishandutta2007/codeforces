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
ll x[500005],y[500005],z[500005];
ll dp[5050][5005];
char s[500005],t[500005],u[500005];
bool dame,flag;
//string s;

int main(){
	cin >> n >> k >> m;
	for(i=0;i<n;i++){
		cin >> x[i];
		sum += x[i];
	}
	sort(x,x+n);
	double ans;
	ans = 0.0f;
	for(i=0;i<n;i++){
		//i
		if(m < i)break;
		ans = max(ans,(double)(sum+min(m-i,k*(n-i)))/(double)(n-i));
		sum -= x[i];
	}


	ps(ans);
	return 0;
}