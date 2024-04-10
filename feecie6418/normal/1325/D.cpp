#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,nd[64],size,ans[1000005];
int f[64];
struct TT{
	int num,val;
	bool operator <(const TT yy) const {
		return num<yy.num;
	}
}a[64];
int main(){
	cin>>x>>y;
	if(y<x)return puts("-1"),0;
	ll now=0;
	for(int i=0;i<61;i++){
		nd[i]=now;
		if(x&(1ll<<i))f[i]=1,now+=(1ll<<i);
	}
	ll sum=0;
	for(int i=61;i>=0;i--){
		int ss=0;
		if(f[i]){
			sum+=(1ll<<i),ss++;
			while(sum+nd[i]+(1ll<<(i+1))<=y)sum+=1ll<<(i+1),ss+=2;
			a[++size]=(TT){ss,i};
		}
		else {
			while(sum+nd[i]+(1ll<<(i+1))<=y)sum+=1ll<<(i+1),ss+=2;
			if(ss)a[++size]=(TT){ss,i};
		}
	}
	if(sum!=y)return puts("-1"),0;
	sort(a+1,a+size+1);
	for(int i=size;i>=1;i--){
		for(int j=1;j<=a[i].num;j++)ans[j]+=(1ll<<a[i].val);
	}
	cout<<a[size].num<<endl;
	for(int i=1;i<=a[size].num;i++)cout<<ans[i]<<' ';
}