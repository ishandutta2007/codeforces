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

long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

const int witness[]={2,7,61};
bool isPrime(int i){
    ///check for the simple cases
    if (i==1) return false;
    if (i==2) return true;
    if (!(i&1)) return false;
    for (auto &it:witness) if (it==i) return true;

    int s=__builtin_ctz(i-1);
    int k=(i>>s);
    
    long long res;
    for (auto &it:witness){
        res=qexp(it,k,i);
        
        if (res==1 || res==i-1) goto pass;
        for (int x=0;x<s-1;x++){
            res=(res*res)%i;
            if (res==i-1) goto pass;
        }
        return false;
        pass:;
    }
    return true;
}


int n;
int pi[1000005];
bool exists[1000005];

vector<int> al[100005];
int w[100005];
int color[100005];
int id[100005];
queue<int> q;


int ans=1e9;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int idx=0;
	rep(x,1,1000005) if (isPrime(x)) pi[x]=idx++;
	
	memset(w,-1,sizeof(w));
	
	cin>>n;
	
	rep(x,0,n){
		int t;
		cin>>t;
		
		vector<int> temp;
		
		rep(x,2,1000){
			if (t%x==0){
				bool can=false;
				while (t%x==0){
					t/=x;
					can^=true;
				}
				
				if (can) temp.push_back(x);
			}
		}
		
		if (t!=1) temp.push_back(t);
		
		if (temp.empty()){
			ans=min(ans,1);
		}
		else if (sz(temp)==1){
			if (exists[temp[0]]) ans=min(ans,2);
			exists[temp[0]]=true;
			
			w[pi[temp[0]]]=0;
			id[pi[temp[0]]]=pi[temp[0]];
			q.push(pi[temp[0]]);
		}
		else{
			if (exists[temp[0]*temp[1]]) ans=min(ans,2);
			exists[temp[0]*temp[1]]=true;
			
			al[pi[temp[0]]].push_back(pi[temp[1]]);
			al[pi[temp[1]]].push_back(pi[temp[0]]);
		}
	}
	
	if (ans<=2){
		cout<<ans<<endl;
		return 0;
	}
	
	while (!q.empty()){
		int node=q.front();
		q.pop();
		
		for (auto &it:al[node]){
			if (w[it]==-1){
				w[it]=w[node]+1;
				id[it]=id[node];
				q.push(it);
			}
			else if (id[it]!=id[node]){
				ans=min(ans,w[it]+w[node]+3);
			}
		}
	}
	
	for (int x=0;x<205;x++){
		memset(w,-1,sizeof(w));
		memset(color,0,sizeof(color));
		int c=1;
		w[x]=0;
		color[x]=0;
		for (vector<int>::iterator it=al[x].begin();it!=al[x].end();it++){
			w[*it]=1;
			color[*it]=c++;
			q.push(*it);
		}
		while (!q.empty()){
			int v=q.front();
			q.pop();
			for (vector<int>::iterator it=al[v].begin();it!=al[v].end();it++){
				if (w[(*it)]==-1){
					w[(*it)]=w[v]+1;
					color[(*it)]=color[v];
					q.push(*it);
				}
				else if (color[*it]!=color[v] && color[*it]!=0){
					ans=min(ans,w[*it]+w[v]+1);
				}
			}
		}
	}

	
	cout<<(ans==1e9?-1:ans)<<endl;
}