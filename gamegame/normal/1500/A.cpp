#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=5e6+1;
ll n;
int a[N];
int p1[N],p2[N],p3[N],p4[N];
void solve(int w,int x,int y,int z){
	cout << "YES\n";
	if(a[w]+a[y]==a[x]+a[z]) cout << w << ' ' << y << ' ' << x << ' ' << z << '\n';
	else cout << w << ' ' << z  << ' ' << x << ' ' << y << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		for(int j=i+1; j<=n ;j++){
			int x=abs(a[i]-a[j]);
			if(p1[x]!=0){
				if(p1[x]!=i && p1[x]!=j && p2[x]!=i && p2[x]!=j){
					solve(p1[x],p2[x],i,j);
					return 0;
				}
				else if(p3[x]!=0){
					if(p4[x]==0){
						if(p1[x]==i || p1[x]==j) continue;
						if(p3[x]!=i && p3[x]!=j){
							solve(p1[x],p3[x],i,j);
							return 0;
						}
						p4[x]=1;
					}
					else{
						if(p3[x]==i || p3[x]==j) continue;
						if(p2[x]!=i && p2[x]!=j){
							solve(p2[x],p3[x],i,j);return 0;
						}
						if(p1[x]!=i && p1[x]!=j){
							solve(p1[x],p3[x],i,j);return 0;
						}
						continue;
					}
				}
				else{
					if(p2[x]==i || p2[x]==j) swap(p1[x],p2[x]);
					p3[x]=i+j-p1[x];
				}
			}
			else{
				p1[x]=i;p2[x]=j;
			}
		}
	}
	cout << "NO\n";
}