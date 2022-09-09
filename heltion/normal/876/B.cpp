#include<bits/stdc++.h>
using namespace std;
vector<int> A[100010];
int main(){
	int n,k,m;
	cin>>n>>k>>m;
	for(int i=0;i<n;++i){
		int a;
		cin>>a;
		A[a%m].push_back(a);
	}
	for(int i=0;i<m;++i)
		if(A[i].size()>=k){
			cout<<"Yes\n";
			for(int j=0;j<k;++j)
			cout<<A[i][j]<<" ";
			return 0;
		}
	cout<<"No";
}