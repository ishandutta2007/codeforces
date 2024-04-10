#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[5500010];
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
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
 
 
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
 
ll n,m,k,num,sum,ans,a,b,c,d,e,g,h,w,i,j,q;
int ad[1005][1005];
char s[500005];
bool flag = false;

void cut(ll v){
	for(i=0;i<n;i++){
		if(i == v)continue;
		ad[i][v] = 1;
		ad[v][i] = 1;
	}
}

int main(){
    cin >> n >> a >> b;
    if(n == 2){
    	if(a == 2 && b == 2){
    		p("NO");
    	}else if(a == 1 && b == 2){
    		p("YES");
    		p("01");
    		p("10");
    		return 0;
    	}else if(a == 2 && b == 1){
    		p("YES");
    		p("00");
    		p("00");
    		return 0;
    	}else{
    		p("NO");
    	}
    	return 0;
    }
    if(a > 1 && b > 1){
    	p("NO");
    }else{
    	if(a != 1){
    		swap(a,b);
    		flag = true;
    	}
    	if(b == 1){
    		if(n == 3){
    			p("NO");
    			return 0;
    		}else{
    			for(i=1;i<n;i++){
    				ad[i][i-1] = 1;
    				ad[i-1][i] = 1;
    			}
    		}
    	}else{

	    	for(int i=0;i<b-1;i++){
	    		cut(i);
	    	}
	    }
	    p("YES");
    	for(i=0;i<n;i++){
    		for(j=0;j<n;j++){
    			if(i == j){
    				pu(0);
    			}else if(flag){
    				pu(1 - ad[i][j]);
    			}else{
    				pu(ad[i][j]);
    			}
    		}
    		el;
    	}


    }
    
    return 0;
}