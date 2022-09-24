#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m,s1[1000005],s2[1000005],s3[1000005],isok[1000005];
char a[1000005];
void Solve(){
	scanf("%d%d%s",&n,&m,a+1);
	for(int i=1;i<=n*m;i++){
		s1[i]=s1[i-1]+(a[i]=='1');
		s2[i]=s2[max(i-m,0)]+(s1[i]-s1[max(i-m,0)]>0);
		isok[i]=(a[i]=='1'||isok[max(i-m,0)]);
		s3[i]=s3[i-1]+isok[i];
		printf("%d ",s2[i]+s3[i]-s3[max(i-m,0)]);
	}
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}