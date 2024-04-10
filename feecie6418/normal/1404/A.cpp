#include<bits/stdc++.h>
using namespace std;
int n,m,s[300005],fa[300005];
char a[300005];
int gf(int x){
	return x!=fa[x]?fa[x]=gf(fa[x]):x;
}
void Solve(){
	scanf("%d%d%s",&n,&m,a+1);
	bool flag=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+(a[i]=='1');
	if(s[m]>m/2)flag=1;
	for(int i=1,j;i<=m;i++){
		j=i;
		int r=-1;
		while(j<=n){
			if(a[j]!='?'){
				if(r!=-1&&a[j]!=r)flag=1;
				else r=a[j];
			}
			j+=m;
		}
		if(r!=-1)a[i]=r;
	}
	for(int i=1;i<=n;i++)s[i]=s[i-1]+(a[i]=='1');
	if(s[m]>m/2)flag=1;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+(a[i]!='0');
	if(s[m]<m/2)flag=1;
	puts(flag?"NO":"YES");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
    return 0;
}