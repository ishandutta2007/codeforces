#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int p,q,x,y;
	cin >> x >> y;
	vector<long long int>a[x+1];
	long long int b[x+1],v[x+1],l[x+1];
	for(int i=1; i<=x ;i++){
		b[i]=0;
		v[i]=0;
		l[i]=1LL;
	}
	for(int i=0; i<y ;i++){
		cin >> p >> q;
		if(q<p){
			swap(p,q);
		}
		a[q].push_back(p);
		b[p]++;
		b[q]++;
	}
	long long int maxi=0;
	for(int i=1; i<=x ;i++){
		for(int j=0; j<a[i].size() ;j++){
			l[i]=max(l[i],l[a[i][j]]+1);
		}
		v[i]=l[i]*b[i];
		maxi=max(maxi,v[i]);
	}
	cout << maxi << endl;
}