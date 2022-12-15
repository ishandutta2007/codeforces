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
	int a[4],d[4];
	FOR(i,0,4) scanf("%d%d",&a[i],&d[i]);

	if( (a[0]>d[2] && d[1]>a[3]) && (a[0]>d[3] && d[1]>a[2]) ){
		cout<<"Team 1"<<endl;
		return 0;
	}
	if( (a[1]>d[2] && d[0]>a[3]) && (a[1]>d[3] && d[0]>a[2]) ){
		cout<<"Team 1"<<endl;
		return 0;
	}

	if(( (a[2]>d[0] && d[3]>a[1]) || (a[3]>d[0] && d[2]>a[1]) ) &&
	 ((a[3]>d[1] && d[2]>a[0]) || (a[2]>d[1] && d[3]>a[0])) ){
		cout<<"Team 2"<<endl;
		return 0;
	}

	cout<<"Draw"<<endl;

	return 0;
}