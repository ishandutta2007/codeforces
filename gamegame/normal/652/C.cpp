#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>c[n+1];
	int a[n+1],b[n+1],d[n+1],p,q;
	for(long long i=1; i<=n ;i++){
		cin >> a[i];
		d[a[i]]=i;
	}
	for(long long i=1; i<=m ;i++){
		cin >> p >> q;
		if(d[p]>d[q]){
			c[p].push_back(q);
		}
		else{
			c[q].push_back(p);
		}
	}
	b[1]=1;
	bool used[n+1];
	for(long long i=1; i<=n ;i++){
		used[i]=false;
	}
	used[a[1]]=true;
	int maxi=0;
	for(long long i=2; i<=n ;i++){
		for(long long j=0; j<c[a[i]].size() ;j++){
			if(used[c[a[i]][j]]){
				maxi=max(maxi,d[c[a[i]][j]]);
			}
		}
		b[i]=i-maxi;
		used[a[i]]=true;
	}
	long long sum=0;
	for(long long i=1; i<=n ;i++){
		sum+=b[i];
	}
	cout << sum << endl;
}