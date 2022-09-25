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

int other(int i){
	return i^1;
}

int r[1050000];

void right_add(int i,int j){
	r[j]=r[i];
	r[i]=j;
}


int n;
int arr[1050000];
int brr[1050000];

bool used[1050000];
vector<int> val[1050000];
int pos[1050000];

vector<int> proc;

void test(int i){
	//debug(i);

	rep(x,0,1050000) pos[x]=-1;
	memset(used,false,sizeof(used));
	rep(x,0,1050000) val[x].clear();
	proc.clear();
	
	int j=(1<<i)-1;
	//cout<<i<<" "<<j<<endl;
	rep(x,0,2*n) brr[x]=arr[x]&j;
	
	rep(x,0,2*n){
		//cout<<x<<" "<<brr[x]<<endl;
		val[brr[x]].push_back(x);
	}
	
	int ls=0;
	r[0]=0;
	right_add(ls,1);
	ls=r[ls];
	
	used[0]=true,used[1]=true;
	pos[brr[ls]]=ls;
	proc.push_back(brr[ls]);
	
	while (brr[ls]!=brr[r[ls]]){
		//cout<<ls->val<<" "<<ls->r->val<<endl;
		while (!val[brr[ls]].empty() && 
			used[val[brr[ls]].back()]) val[brr[ls]].pop_back();
			
		if (val[brr[ls]].empty()) return;
		
		int temp=val[brr[ls]].back();
		right_add(ls,temp);
		ls=r[ls];
		right_add(ls,other(temp));
		ls=r[ls];
		
		used[temp]=true,used[other(temp)]=true;
		pos[brr[ls]]=ls;
		proc.push_back(brr[ls]);
	}
	
	while (!proc.empty()){
		int t=proc.back();
		proc.pop_back();
		
		//cout<<"debug: "<<t<<endl;
		
		while (!val[t].empty() && 
			used[val[t].back()]) val[t].pop_back();
			
		if (val[t].empty()) continue;
		
		t=val[t].back();
		
		ls=pos[brr[t]];
		right_add(ls,t);
		ls=r[ls];
		right_add(ls,other(t));
		ls=r[ls];
		
		used[t]=true,used[other(t)]=true;
		pos[brr[ls]]=ls;
		proc.push_back(brr[ls]);
	
	//bruh
	while (brr[ls]!=brr[r[ls]]){
		//cout<<ls->val<<" "<<ls->r->val<<endl;
		while (!val[brr[ls]].empty() && 
			used[val[brr[ls]].back()]) val[brr[ls]].pop_back();
			
		if (val[brr[ls]].empty()) return;
		
		int temp=val[brr[ls]].back();
		right_add(ls,temp);
		ls=r[ls];
		right_add(ls,other(temp));
		ls=r[ls];
		
		used[temp]=true,used[other(temp)]=true;
		pos[brr[ls]]=ls;
		proc.push_back(brr[ls]);
	}
	
	}
	
	rep(x,0,2*n) if (!used[x]){
		return;
	}
	
	cout<<i<<endl;
	rep(x,0,2*n){
		ls=r[ls];
		cout<<ls+1<<" ";
	}
	/*
	cout<<endl;
	rep(x,0,2*n){
		ls=ls->r;
		cout<<brr[ls->val]<<" ";
	}
	*/
	exit(0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x*2]>>arr[x*2+1];
	
	
	rep(x,21,0) test(x);
}