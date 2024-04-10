#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define ll long long
int T,i,j,n,a[N],x,y,pos;
char s[N],ch;
unsigned ll ans;
int main(){
	cin>>n>>T;
	scanf("%s",s+10);
	for(i=10;i<n+10;++i)if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')++ans; 
//	T=1;
	while(T--){
		cin>>pos>>ch;
		for(i=pos+9-3;i<=10+pos;++i)if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')--ans; 
		s[pos+9]=ch;
		for(i=pos+9-3;i<=10+pos;++i)if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')++ans; 
		cout<<ans<<"\n";
	}
	return 0;
}