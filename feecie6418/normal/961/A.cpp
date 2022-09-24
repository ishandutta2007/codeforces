#include<iostream>
//5466
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[1005],minn;
//jewerju4iutiru
int main() {
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>minn;
		a[minn]++;
	}
	minn=0x3f3f3f3f;
	for(int i=1;i<=n;i++)minn=min(minn,a[i]);
	cout<<minn<<endl;
	return 0;
}