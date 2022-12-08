#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m,t;
	cin>>n>>m;
	m<<=1;
	while(m--)cin>>t;
	for(int i=1;i<=n;i++)
		putchar('0'+(i&1));
	puts("");
	return 0;
}