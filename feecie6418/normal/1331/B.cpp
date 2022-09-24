#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<ctime>
#include<cmath>
using namespace std;
int main() {
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)if(n%i==0)return cout<<i<<(n/i)<<endl,0;
	return 0;
}