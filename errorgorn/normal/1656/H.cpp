//
//

#include <bits/stdc++.h>
using namespace std;

#define int __int128
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

void read(int &x){
	x=0;
	char ch=getchar();
	while (ch&16){
		x=x*10+(ch&15);
		ch=getchar();
	}
}

void write(int &x){
	string s;
	while (x){
		s+='0'+(x%10);
		x/=10;
	}
	
	reverse(all(s));
	cout<<s<<" ";
}

int gcd(int a,int b){
	while (b){
		int temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

int lcm(int a,int b){
	int temp=gcd(a,b);
	return a/temp*b;
}

struct node{
	int tree[2100];
	const int BUF=1050;
	
	node(){
		rep(x,0,2100) tree[x]=1;
	}
	
	void update(int i,int k){
		i+=BUF;
		tree[i]=k;
		i>>=1;
		
		while (i){
			tree[i]=lcm(tree[i<<1],tree[i<<1|1]);
			i>>=1;
		}
	}
	
	int query(int i,int j){
		i+=BUF,j+=BUF+1;
		int res=0;
		
		while (i<j){
			if (i&1){
				res=lcm(res,tree[i]);
				i++;
			}
			if (j&1){
				j--;
				res=lcm(res,tree[j]);
			}
			i>>=1,j>>=1;
		}
		return res;
	}
} root1[1005],root2[1005];

int n,m;
int arr[1005];
int brr[1005];
bool has1[1005];
bool has2[1005];


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	read(TC);
	while (TC--){
		read(n),read(m);
		rep(x,0,n) read(arr[x]);
		rep(x,0,m) read(brr[x]);
		rep(x,0,n) has1[x]=true;
		rep(x,0,m) has2[x]=true;
		
		
		rep(x,0,n) rep(y,0,m) root1[x].update(y,gcd(arr[x],brr[y]));
		rep(x,0,n) rep(y,0,m) root2[y].update(x,gcd(brr[y],arr[x]));
		
		while (true){
			bool bad=false;
			rep(x,0,n) if (has1[x] && root1[x].tree[1]!=arr[x]){
				rep(y,0,m) root2[y].update(x,1);
				has1[x]=false;
				bad=true;
			}
			rep(x,0,m) if (has2[x] && root2[x].tree[1]!=brr[x]){
				rep(y,0,n) root1[y].update(x,1);
				has2[x]=false;
				bad=true;
			}
			
			if (!bad) break;
		}
		
		int s1=0,s2=0;
		rep(x,0,n) if (has1[x]) s1++;
		rep(x,0,m) if (has2[x]) s2++;
		
		if (s1 && s2){
			cout<<"YES"<<endl;
			write(s1),write(s2),cout<<endl;
			rep(x,0,n) if (has1[x]) write(arr[x]); cout<<endl;
			rep(x,0,m) if (has2[x]) write(brr[x]); cout<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
		rep(x,0,n) rep(y,0,m){
			root1[x].update(y,1);
			root2[y].update(x,1);
		}
	}
}