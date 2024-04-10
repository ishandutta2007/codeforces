#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
//#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,t,cur;
int rev[305];
vector<int>vec;
int ans[305],curr[305];
void ask(int L,int R){
	cout<<"? "<<L<<" "<<R<<endl; fflush(stdout);
	return ;
	/*srand((unsigned)time(NULL));
	int s = rand()%2;
	if(s == 0){
		for(int i=1;i<=R;i++) curr[i] ^= 1;
	}
	else{
		for(int i=L;i<=n;i++) curr[i] ^= 1;
	}*/
}
int C = 0;
void listen_to(int &a){
	cin>>a; return;
	/*int ret = 0;
	for(int i=1;i<=n;i++) ret += curr[i];
	a = ret; C++;
	return ;*/
}
void doE(){
	for(int i=0;i<n;i++){
		while(1){
			ask(i+1,i+1);
			int x; cin>>x;
			int a = (cur%2)^(x%2);
			int b = (i+1)%2;
			if(a == b){
				//ok!
				int num = 0;
				for(int j=0;j<vec.size();j++){
					num += vec[j];
					vec[j] ^= 1;
				}
				int sz = vec.size();
				if(sz+1-2*num == x-cur){
					vec.pb(1);
				}
				else{
					vec.pb(0);
				}
				for(int j=0;j<=i;j++) rev[j]^=1;
				cur = x;
				break;
			}
			else{	
				//ng
				for(int j=i;j<n;j++) rev[j]^=1;
				cur = x;
			}
		}
	}
	cout<<"!"<<" ";
	for(int i=0;i<n;i++)cout<<(rev[i]^vec[i]);
	cout<<endl;
}
void doO(){
	for(int i=0;i<n-1;i+=2){
		while(1){
			ask(i+1,i+2);
			int x; listen_to(x);
			int a = ((cur%2)^(x%2));
			int b = (i+2)%2;
			if(a == b){
				//ok!
				int num = 0;
				for(int j=0;j<vec.size();j++){
					num += vec[j];
					vec[j] ^= 1;
				}
				for(int j=0;j<=i+1;j++) rev[j]^=1;
				int sz = vec.size();
				if(sz+2-2*num == x-cur){
					vec.pb(1); vec.pb(1); cur = x; break;
				}
				else if(sz+2-2*num-4 == x-cur){
					vec.pb(0); vec.pb(0); cur = x; break;
				}
				else{
					cur = x;
					while(1){
						ask(i+2,i+3);
						int y; listen_to(y);
						int a = (y%2)^(cur%2);
						int b = (i+3)%2;
						if(a != b){
							//ok!
							cur = y;
							for(int x=i+1;x<n;x++) rev[x]^=1;
							goto nxt;
						}
						else{
							for(int x=0;x<vec.size();x++){
								vec[x]^=1;
								rev[x]^=1;
							}
							for(int x=i;x<=i+2;x++) rev[x]^=1;
							cur = y;
						}
					}
					nxt:;
					continue;
				}
			}
			else{	
				//ng
				for(int j=i;j<n;j++) rev[j]^=1;
				cur = x;
				continue;
			}
		}
	}
	int num = 0;
	for(int i=0;i<n-1;i++) num += vec[i];
	vec.pb(cur-num);
	cout<<"!"<<" ";
	for(int i=0;i<n;i++)cout<<(rev[i]^vec[i]);
	cout<<endl;
}
int main(){
	cin>>n>>t;
	cur = t;
	if(n%2 == 0) doE();
	else doO();
	return 0;
}