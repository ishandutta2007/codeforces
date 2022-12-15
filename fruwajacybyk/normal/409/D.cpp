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

int t[]={
1, //1 T
0, // TT
0, //3 TT
1, //  TT 
0, //5 TT
1, //  T
0, //7 T
1, //  T
1, //9 T
1, // T
0, //11 T
0, //12 TT
1, //13 T
0,
1, //15 T
0}; //T


int main(){
	int n;
	scanf("%d",&n);
	cout<<t[n-1]<<endl;
	return 0;
}