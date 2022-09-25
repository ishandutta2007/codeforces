//
//

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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

vector<vector<long long> > mul(vector<vector<long long> > i, vector<vector<long long> > j,int m){
    vector<vector<long long> > res;
    for (int x=0;x<i.size();x++){
        res.push_back(vector<long long>());
        for (int y=0;y<i.size();y++){
            res[x].push_back(0);
            for (int z=0;z<i.size();z++){
                res[x][y]=(res[x][y]+i[x][z]*j[z][y])%m;
            }
        }
    }
    return res;
}

vector<vector<long long> > mexp(vector<vector<long long> > mat,long long p,int m){
    if (p==1) return mat;
    vector<vector<long long> > res=mexp(mat,p>>1,m);
    res=mul(res,res,m);
    if (p&1) res=mul(res,mat,m);
    return res;
}

ll n,k;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	vector<vector<ll> > mat;
	
	rep(x,0,k){
		mat.push_back(vector<ll>());
		rep(y,0,k){
			mat[x].push_back(0);
		}
	}
	
	mat[0][0]=1;
	mat[0][k-1]=1;
	rep(x,0,k-1) mat[x+1][x]=1;
	
	mat=mexp(mat,n,1000000007);
	
	cout<<mat[0][0];
	
}