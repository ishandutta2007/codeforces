#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int a,b,x;
int main(){
	cin>>a>>b>>x;
	if(x%2 == 0){
		string ret = "";
		if(a>=b){
			for(int i=0;i<x+1;i++){
				if(i == x){
					while(a) ret.pb('0'),a--;
				}
				else if(i == x-1){
					while(b) ret.pb('1'),b--;
				}
				else if(i%2 == 0){
					ret.pb('0'),a--;
				}
				else{
					ret.pb('1'),b--;
				}
			}cout<<ret<<endl;
		}
		else{
			swap(a,b);
			for(int i=0;i<x+1;i++){
				if(i == x){
					while(a) ret.pb('1'),a--;
				}
				else if(i == x-1){
					while(b) ret.pb('0'),b--;
				}
				else if(i%2 == 0){
					ret.pb('1'),a--;
				}
				else{
					ret.pb('0'),b--;
				}
			}cout<<ret<<endl;
		}
	}
	else{
		string ret = "";
		for(int i=0;i<x+1;i++){
			if(i == x){
				while(a) ret.pb('0'),a--;
			}
			else if(i == x-1){
				while(b) ret.pb('1'),b--;
			}
			else if(i%2 == 1){
				ret.pb('0'),a--;
			}
			else{
				ret.pb('1'),b--;
			}
		}cout<<ret<<endl;
	}
	//cout<<ret<<endl;
}