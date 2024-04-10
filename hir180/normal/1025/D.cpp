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
int n,a[705];
bool *ok[705];
bool L[705][705],R[705][705];
bool xx[705][705];
int main(){
	cin>>n;
	rep(i,n) cin>>a[i];
	rep(i,n)rep(j,n) if(__gcd(a[i],a[j])>=2)xx[i][j]=1;
	for(int i=0;i<n;i++) ok[i] = new bool[(n-i)*(n-i)];
	rep(i,n) ok[i][0] = 1;
	rep(i,n) L[i][i] = R[i][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j+i-1<n;j++){
			//L[j][j+i-1]
			//R[j][j+i-1]
			for(int x=j;x<j+i-1;x++){
				if(xx[x][j+i-1] && ok[j][(n-j)*(j+i-2-j)+(x-j)]){
					L[j][j+i-1] = 1; break;
				}
			}
			for(int x=j+1;x<=j+i-1;x++){
				if(xx[x][j] && ok[j+1][(n-j-1)*(j+i-1-j-1)+(x-j-1)]){
					R[j][j+i-1] = 1; break;
				}
			}
		}
		for(int j=0;j+i-1<n;j++){
			//ok[j][j+i-1][x]
			for(int x=j;x<=j+i-1;x++) ok[j][(n-j)*(j+i-1-j)+x-j] = (L[j][x]&&R[x][j+i-1]);
		}
	}
	for(int i=0;i<n;i++) if(ok[0][n*(n-1)+i]){
		puts("Yes");
		return 0;
	}
	puts("No");
}