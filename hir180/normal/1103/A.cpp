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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
bool u[5][5];
string str;
int main(){
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i] == '0'){
			if(!u[1][1]){
				u[1][1] = 1;
				u[2][1] = 1;
				cout<<1<<" "<<1<<endl;
			}
			else{
				u[3][1] = 1;
				u[4][1] = 1;
				cout<<3<<" "<<1<<endl;
			}
			if(u[1][1]&&u[2][1]&&u[3][1]&&u[4][1]){
				repn(f,4) u[f][1] = 0;
			}
		}
		else{
			for(int j=1;j<=4;j++){
				if(!u[j][3]){
					u[j][3] = u[j][4] = 1;
					cout<<j<<" "<<3<<endl;
					break;
				}
			}
			if(u[1][3]&&u[2][3]&&u[3][3]&&u[4][3]){
				repn(f,4) u[f][3] = u[f][4] = 0;
			}
		}
	}
}