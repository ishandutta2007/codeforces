#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[300005],x,s[300005],c[300005];
ll ans=0;
struct Thing{
	int id,x;
	bool operator <(const Thing o)const{
		return x<o.x;
	} 
}b[300005];
ll Check(int w,int x){
	ll ret=0;
	for(int i=1;i<=n;i++){
		int u=a[i]^x;
		b[i]={i,((u>>(w+1))<<(w+1))};
		s[i]=0;
	}
	sort(b+1,b+n+1);
	for(int i=1,now=0;i<=n;i++){
		if(i==1||(b[i].x!=b[i-1].x))now++;
		c[b[i].id]=now;
	}
	for(int i=1;i<=n;i++){
		int u=a[i]^x;
		if(!((u>>w)&1))ret+=s[c[i]];
		else s[c[i]]++;
	} 
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=29;i>=0;i--){
		ll p=Check(i,x),pp=Check(i,x^(1<<i));
		if(p>pp)x^=(1<<i),ans+=pp;
		else ans+=p;
	}
	cout<<ans<<' '<<x<<endl;
    return 0;
}