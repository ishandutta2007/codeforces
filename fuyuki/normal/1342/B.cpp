#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+1;
int T,n;
char a[N];
I same(){
	FOR(i,1,n)if(a[i]!=a[1])return 0;
	return 1;
}
int main(){
	for(scanf("%d",&T);T--;){
    	scanf("%s",a+1),n=strlen(a+1);
    	if(same())cout<<a+1;
    	else FOR(i,1,n*2)cout<<"01"[i&1];
    	cout<<'\n';
	}
	return 0;
}