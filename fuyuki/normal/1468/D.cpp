#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,block=400,mod=998244353;
typedef long long ll;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
int n,m,a,b,x,y;
int s[N];
inline bool check(int mid){
	int c=0;
	for(int i=mid;i>=1;i--) {
		if(y-s[i]<c) return 0;
		c++;
	}
	return 1;
}
int main(){
	int t=read();
	while(t--){
		n=read(),m=read(),a=read(),b=read();
		for(int i=1;i<=m;i++) s[i]=read();
		sort(s+1,s+m+1);
		if(a<b) x=b-a-1,y=b-2;
		else x=a-b-1,y=n-b-1;
		int l=1,r=min(x,m),ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}