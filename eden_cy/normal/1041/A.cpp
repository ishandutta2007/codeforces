#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)

int A[10005];
int main() {
	int n;
	cin>>n;
	FOR(i,1,n) scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	cout<<A[n]-A[1]+1-n<<endl;
	return 0;
}