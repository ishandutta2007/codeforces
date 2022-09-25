#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

const string num[]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int n,k;
string board[2005];

int memo[2005][2005];

int cmp(int i,int j){ //ith board against jth digit
	int res=0;
	
	rep(x,0,7){
		if (board[i][x]=='0' && num[j][x]=='1'){
			res++;
		}
		else if (board[i][x]=='1' && num[j][x]=='0'){
			return -1;
		}
	}
	
	return res;
}

int dp(int i,int val){ //consider ith element
	if (val<0) return 0;
	if (memo[i][val]!=-1) return memo[i][val];

	if (i==n){
		if (val==0) return memo[i][val]=1;
		else return memo[i][val]=0;
	}
	
	rep(x,10,0){
		int v=cmp(i,x);
		
		if (v!=-1 && dp(i+1,val-v)) return memo[i][val]=1;
	}
	
	return memo[i][val]=0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(memo,-1,sizeof(memo));
	
	cin>>n>>k;
	rep(x,0,n) cin>>board[x];
	
	if (dp(0,k)){
		int curr=k;
		
		rep(x,0,n){
			rep(y,10,0){
				int v=cmp(x,y);
				
				if (v!=-1 && dp(x+1,curr-v)){
					curr-=v;
					cout<<(char)('0'+y);
					break;
				}
			}
		}
	}
	else{
		cout<<"-1"<<endl;
	}
}