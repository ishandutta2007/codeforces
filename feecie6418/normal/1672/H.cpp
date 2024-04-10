#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,q,s[200005][2];
char a[200005];
int main(){
	scanf("%d%d%s",&n,&q,a+1);
	for(int i=2;i<=n;i++){
		s[i][0]=s[i-1][0]+(a[i]=='0'&&a[i-1]=='0');
		s[i][1]=s[i-1][1]+(a[i]=='1'&&a[i-1]=='1');
	}
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",1+max(s[r][0]-s[l][0],s[r][1]-s[l][1]));
	}
}