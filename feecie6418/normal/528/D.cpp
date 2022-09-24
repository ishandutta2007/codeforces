#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,K,id[205];
char a[200005],b[200005],t[]={"ACGT"};
bitset<200005> ans,p[4];
int main(){
	cin>>n>>m>>K>>a+1>>b+1;
	for(int i=1;i<=n;i++)ans[i]=1;
	for(int s=0;s<4;s++){
		id[t[s]]=s;
		for(int i=1,lst=-1e9;i<=n;i++){
			if(a[i]==t[s])lst=i;
			if(i-lst<=K)p[s][i]=1;
		}
		for(int i=n,lst=1e9;i>=1;i--){
			if(a[i]==t[s])lst=i;
			if(lst-i<=K)p[s][i]=1;
		}
	}
	for(int i=1;i<=m;i++)ans&=p[id[b[i]]]>>i-1;
	cout<<ans.count();
}