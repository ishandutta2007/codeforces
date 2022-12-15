#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;


int main(){
	int a,b;
	double x; cin>>x;
	FOR(i,1,11) FOR(j,1,11){
		if( abs((i*j)*1./(sqrt(i*i+4*j*j)) -x) < 0.00001){
			cout<<i<<" "<<j<<endl;
			return 0;
		}
	}
	return 0;
}