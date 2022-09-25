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

int arr[2100];

int memo[2100][2100];
int get(int i,int j){
	if (memo[i][j]!=-1) return memo[i][j];
	
	//*
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	int res;
	cin>>res;
	//*/
	
	//int res=arr[i]|arr[j];
	
	if (res==-1){
		exit(1); //bruh
	}
	
	return memo[i][j]=memo[j][i]=res;
}

int n;
vector<int> v;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(memo,-1,sizeof(memo));
	
	cin>>n;
	
	//rep(x,0,n) cin>>arr[x];
	
	rep(x,0,n) v.push_back(x);
	
	int zero=-1;
	
	int bits=11;
	
	while (sz(v)>2){
		//cout<<"debug: ";
		//for (auto &it:v) cout<<it<<" ";
		//cout<<endl;
		
		int curr,curr2;
		do{
			curr=rng()%sz(v);
			curr2=rng()%sz(v);
			//cout<<"debug: "<<curr<<" "<<curr2<<endl;
		} while (curr==curr2 || __builtin_popcount(get(v[curr],v[curr2]))>(bits)/2);
		
		int bm=2047;
		for (auto &it:v) if (it!=v[curr]){
			bm&=get(v[curr],it);
		}
		
		if (bm==0){
			zero=v[curr];
			break;
		}
		
		bits=__builtin_popcount(bm);
		
		vector<int> temp;
		for (auto &it:v) if (it!=v[curr]){
			if ((get(it,v[curr])&bm)==get(it,v[curr])) temp.push_back(it);
		}
		
		swap(v,temp);
	}
	
	//cout<<"ok"<<endl;
	//cout<<"debug: ";
	//for (auto &it:v) cout<<it<<" ";
	//cout<<endl;
	
	if (sz(v)==1) zero=v[0];
	else if (sz(v)==2){
		while (true){
			int curr=rng()%n;
			
			if (curr!=v[0] && curr!=v[1] && get(curr,v[0])!=get(curr,v[1])){
				if (get(curr,v[0])<get(curr,v[1])) zero=v[0];
				else zero=v[1];
				
				break;
			}
		}
	}
	
	vector<int> ans;
	rep(x,0,n){
		if (x==zero) ans.push_back(0);
		else ans.push_back(get(x,zero));
	}
	
	cout<<"! ";
	for (auto &it:ans) cout<<it<<" ";
}