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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
bitset<7005>B[100005];
bitset<7005>sqfr[7005],divv[7005];
bool ok[7005];
int n,q;
string str = "";
int main(){
	scanf("%d%d",&n,&q);
	for(int i=4;i<=7000;i++){
		int m = i;
		for(int j=2;j*j<=m;j++){
			int c = 0;
			while(m%j==0){
				m/=j;
				c++;
			}
			if(c >= 2) ok[i] = 1;
		}
	}
	for(int i=1;i<=7000;i++){
		for(int j=1;i*j<=7000;j++){
			if(!ok[j]) sqfr[i][i*j] = 1;
			divv[i*j][i] = 1;
		}
	}
	rep(i,q){
		int t; scanf("%d",&t);
		if(t == 1){
			int x,v; scanf("%d%d",&x,&v);
			B[x] = divv[v]; 
		}
		else if(t == 4){
			int x,v; scanf("%d%d",&x,&v);
			int a = (B[x]&sqfr[v]).count()%2;
			str.pb('0'+a);
		}
		else if(t == 2){
			int x,y,z; scanf("%d%d%d",&z,&y,&x);
			B[z] = B[x]^B[y];
		}
		else if(t == 3){
			int x,y,z; scanf("%d%d%d",&z,&y,&x);
			B[z] = B[x]&B[y];
		}
	}
	cout<<str<<endl;
}