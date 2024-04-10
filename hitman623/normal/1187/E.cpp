#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
  
#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int n,subtree_size[200005],sum,final_answer;
vi adj[200005];
void dfs(int node, int par){
	subtree_size[node] = 1;
	for(auto child:adj[node]){
		if(child==par) continue;
		dfs(child, node);
		subtree_size[node] += subtree_size[child];
	}
}

void dfs2(int node, int par){
	// currently node is the root and values are in accordance with that
	int answer_when_node_is_root = sum;
	final_answer = max(final_answer, answer_when_node_is_root);	
	for(auto child:adj[node]){
		if(child==par) continue;
		// reroot from node to child
		int copy_root = subtree_size[node];
		int copy_child = subtree_size[child];
		int copy_sum = sum;
		subtree_size[node] = subtree_size[node] - subtree_size[child];
		subtree_size[child] = n;
		sum -= copy_child + copy_root;
		sum += subtree_size[child] + subtree_size[node];
		// made child as the root and updated the arrays
		dfs2(child, node);
		// set root back to node
		subtree_size[node] = copy_root;
		subtree_size[child] = copy_child;
		sum = copy_sum;
	}
}

void solve(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
    dfs(1, -1);
    for(int i=1;i<=n;i++) sum+=subtree_size[i];
    dfs2(1, -1);
	cout<<final_answer<<endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}