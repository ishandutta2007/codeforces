#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,N=1e6;
int n,a[300005],c[10000005][2],s[10000005],tot=1,rt=1;
void Ins(int x){
	int p=rt;
	for(int i=29;i>=0;i--){
		int w=((x>>i)&1);
		if(!c[p][w])c[p][w]=++tot;
		p=c[p][w],s[p]++;
	}
}
int Get(int x){
	int ans=0,p=rt;
	for(int i=29;i>=0;i--){
		int w=((x>>i)&1);
		if(!s[c[p][w]])ans|=(1<<i),p=c[p][!w];
		else p=c[p][w];
		s[p]--;
	}
	return ans;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),Ins(x);
	for(int i=1;i<=n;i++)cout<<Get(a[i])<<' ';
}