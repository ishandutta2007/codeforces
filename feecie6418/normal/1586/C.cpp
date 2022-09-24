#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s[1000005];
string a[1000005];
char tmp[1000005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",tmp+1),a[i]=tmp+1;
	for(int i=1;i<m;i++){
		for(int j=2;j<=n;j++){
			if(a[j][i-1]=='X'&&a[j-1][i]=='X')s[i]++;
		}
		s[i]+=s[i-1];
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r),l--,r--;
		puts((s[r]-s[l]==0)?"YES":"NO");
	}
}