#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 510;
int n,k;
int valA,A,valB,B;
int sm;

int main() {_
	cin>>n>>k;
	cout<<"? ";
	for(int i=1; i<=k; i++) {
		cout<<i<<" ";
	}
	cout<<"\n";
	cout.flush();
	cin>>A>>valA;
	cout<<"? ";
	for(int i=1; i<=k+1; i++) {
		if(i==A) continue;
		cout<<i<<" ";
	}
	cout<<"\n";
	cout.flush();
	cin>>B>>valB;
	if(valB<valA) {
		swap(A,B); swap(valA,valB);
	}
	for(int i=1; i<=k+1; i++) {
		if(i==A||i==B) continue;
		cout<<"? ";
		for(int j=1; j<i; j++) {
			cout<<j<<" ";
		}
		for(int j=i+1; j<=k+1; j++) {
			cout<<j<<" ";
		}
		cout<<"\n";
		cout.flush();
		int valT, T;
		cin>>T>>valT;
		if(valT>valA) sm++;
	}
	cout<<"! "<<sm+1<<"\n";
	cout.flush();
	
	
}