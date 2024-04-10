#include<bits/stdc++.h>
using namespace std;
char a[100005],b[100005];
int n,fa[200];
int gf(int x){
	return fa[x]==x?x:gf(fa[x]);
}
int main(){
	int oo;
	cin>>oo;
	while(oo--){
		int u[30][30]={0},ans=0,f=0;
		scanf("%d%s%s",&n,a+1,b+1);
		for(int i=1;i<=n;i++){
			if(b[i]<a[i])f=1;
			if(b[i]>a[i])if(!u[a[i]-'a'][b[i]-'a'])u[a[i]-'a'][b[i]-'a']=1;
		}
		if(f)puts("-1");
		else {
			for(int j=1;j<=26;j++)fa[j]=j;
			for(int j=0;j<26;j++){
				for(int k=0;k<26;k++)if(u[j][k])fa[gf(j+1)]=gf(k+1);
			}
			for(int j=1;j<=20;j++)if(gf(j)==j)ans++;
			cout<<20-ans<<endl;
		}
	}
}