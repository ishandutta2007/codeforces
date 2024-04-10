#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[100005],b[100005];
int n,m,top,f[100005][2];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>a+1>>b+1,n=strlen(a+1),m=strlen(b+1);
		f[0][0]=f[1][0]=0,f[1][1]=(a[1]==b[1]?1:-1e9),f[0][1]=-1e9;
		for(int i=2;i<=n;i++){
			f[i][0]=0;
			if(f[i-1][1]>=0&&b[f[i-1][1]+1]==a[i])f[i][0]=max(f[i][0],f[i-1][1]+1);
			f[i][0]=max(f[i][0],f[i-2][0]);
			f[i][1]=-1e9;
			if(f[i-1][0]>=0&&b[f[i-1][0]+1]==a[i])f[i][1]=max(f[i][1],f[i-1][0]+1);
			f[i][1]=max(f[i][1],f[i-2][1]);
		}
		if(f[n][m&1]==m)puts("YES");
		else puts("NO");
		for(int i=1;i<=n;i++)f[i][0]=f[i][1]=a[i]=0;
		for(int i=1;i<=m;i++)b[i]=0;
	}
}