#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int n,a[27],b[27];
char s[N];
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	cin>>n>>s;
	int i,j;
	for(i=0;i<n;++i)
		++a[s[i]-'a'];
	for(i=0;i<26;++i)
		for(j=0;j<a[i];++j)
			putchar(i+'a');
}