#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,s[200005],lst[400005];
char str[200005];
void Solve(){
	cin>>n>>str+1;
	if(is_sorted(str+1,str+n+1))return puts("0"),void();
	int c0=0,c1=0,ans=0;
	for(int i=1;i<=n;i++)c0+=(str[i]=='0');
	c1=n-c0;
	if(c0<c1){
		reverse(str+1,str+n+1),swap(c0,c1);
		for(int i=1;i<=n;i++)str[i]^=1;
	}
	s[n+1]=0,lst[n]=n+1;
	for(int i=n;i>=1;i--){
		s[i]=s[i+1]+(str[i]=='0'?1:-1);
		if(!lst[s[i]+n])lst[s[i]+n]=i;
	}
	int i=1;
	while(c0>c1){
		if(str[i]=='0'){
			i++,c0--;
			continue;
		}
		int pos=lst[s[i]+n]-1;
		ans++,sort(str+i,str+pos+1);
		for(int j=pos;j>=i;j--)if(lst[s[j]+n]==j)lst[s[j]+n]=0;
		for(int j=pos;j>=i;j--){
			s[j]=s[j+1]+(str[j]=='0'?1:-1);
			if(!lst[s[j]+n])lst[s[j]+n]=j;
		}
		i++,c0--;
	}
	cout<<ans+1<<'\n';
	for(int i=0;i<=2*n;i++)lst[i]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}