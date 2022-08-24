#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
int n,k;
int ans=0,res;
bool fun=false;

int d[N];
int prv[N];
int is[N];
void go(vector<int>&v){
	cout << "? ";
	for(auto c:v){
		cout << c << ' ';
		is[c]^=1;
	}
	cout << endl;
	v.clear();
	cin >> res;ans^=res;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=0; i<n ;i++){
		d[i]=1e9;
	}
	queue<int>q;q.push(n);
	while(!q.empty()){
		int x=q.front();q.pop();
		int in=x,out=n-x;
		for(int i=0; i<=k ;i++){
			if(i<=in && k-i<=out){
				int nx=x-i+(k-i);
				if(d[nx]>d[x]+1){
					d[nx]=d[x]+1;
					prv[nx]=x;
					q.push(nx);
				}
			}
		}
	}
	if(d[0]==1e9) return cout << "-1" << endl,0;
	int x=0;
	while(x!=n){
		int nx=prv[x];
		vector<int>tin,tout,v;
		for(int i=1; i<=n ;i++){
			if(is[i]) tin.push_back(i);
			else tout.push_back(i);
		}
		int in=x,out=n-x;
		for(int i=0; i<=k ;i++){
			if(nx==x-i+(k-i)){
				for(int j=1; j<=i ;j++){
					v.push_back(tin.back());tin.pop_back();
				}
				for(int j=1; j<=k-i ;j++){
					v.push_back(tout.back());tout.pop_back();
				}
				go(v);
			}
		}
		x=nx;
	}
	cout << "! " << ans << endl;
}