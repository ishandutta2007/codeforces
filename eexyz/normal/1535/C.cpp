#include<bits/stdc++.h>
using namespace std;
#define pf push_front
#define pb push_back
#define N 200005
#define ll long long
int i,j,k,n,T,x,y,v,l,a[N],l0,l1;
long long ans;
char s[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	cin>>T;
	while(T--){
		scanf("%s",s+1);l=strlen(s+1);ans=0;
		for(i=1;i<=l;++i){
			if(s[i]!='?')s[i]^=(i&1);
		}
		l0=l1=0;
		for(i=1;i<=l;++i){
			if(s[i]=='?')a[i]=a[i-1]+1;
			else if(s[i]=='0'){
				a[i]=i-l1,l0=i;
			}
			else a[i]=i-l0,l1=i;
			ans+=a[i]; 
		}
		cout<<ans<<"\n";
	}
}