#include<bits/stdc++.h>
using namespace std;
typedef long long L;
const int N=2e5+11;
char s[N];
char t[N];
int p,a;
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	int n,k,i;
	cin>>n>>k;
	scanf("%s",s+1);
	for(i=1;i<=n;++i)
		if(s[i]==')'){
			if(a){
				t[++p]=')';
				--a;
			}
		}else if(k){
			k-=2;
			t[++p]='(';
			++a;
		}
	puts(t+1);
}