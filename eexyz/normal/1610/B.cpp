#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
#define py cout<<"YES\n"
#define pn cout<<"NO\n";
vector<int>son[N];
void dfs(int now,int fat){
	for(int T,i=0;i<son[now].size();++i)
		if((T=son[now][i])!=fat)dfs(T,now);
}
int T,n,i,j,x,y,m,a[N],pos,cnt,b[N],fl;
int main(){
	T=1;
cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		pos=-1;
		for(i=1;i<=n;++i){
			if(a[i]!=a[n-i+1]){pos=i;break;}
		}
		if(pos==-1)py;
		else{
			cnt=0;
			for(i=1;i<=n;++i)if(a[i]!=a[pos])b[++cnt]=a[i];
			fl=0;for(i=1;i<=cnt;++i)if(b[i]!=b[cnt+1-i])fl=1;
			if(!fl){py;continue;}
			cnt=0;
			for(i=1;i<=n;++i)if(a[i]!=a[n-pos+1])b[++cnt]=a[i];
			fl=0;for(i=1;i<=cnt;++i)if(b[i]!=b[cnt+1-i])fl=1;
			if(!fl)py;
			else pn;
		}
	}
}