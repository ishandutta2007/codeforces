#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
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
int a[11],b[11];
int n;
int main(){
	rep(i,10) a[i]=0,b[i]=1;
	cin>>n;
	rep(i,n){
		string s; int v; cin>>s>>v;
		if(s == "|"){
			rep(j,10)if(((v>>j)&1)){
				a[j] = b[j] = 1;
			}
		}
		else if(s == "^"){
			rep(j,10)if(((v>>j)&1)){
				a[j]=1-a[j]; b[j]=1-b[j];
			}
		}
		else{
			rep(j,10)if(!((v>>j)&1)){
				a[j] = b[j] = 0;
			}
		}
	}
	int x=0,y=0,z=0;
	for(int i=0;i<10;i++){
		if(a[i]==b[i] && a[i]==0);
		else x+=1<<i;
		if(a[i]==1&&b[i]==0){
			y+=1<<i;
		}
		if(a[i]==1&&b[i]==1){
			z+=1<<i;
		}
	}
	cout<<3<<endl;
	cout<<"& "<<x<<endl;
	cout<<"^ "<<y<<endl;
	cout<<"| "<<z<<endl;
}