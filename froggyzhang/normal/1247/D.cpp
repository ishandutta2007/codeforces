#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
#define N 100010
map<vector<int>,int> mp;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
ll n,a[N],k,p,ans,buc[N],mx;
vector<int> tmp;
ll ok(ll p){
	ll mul=1;
	for(int i=1;i<=k;i++){
		mul*=p;
		if(mul>mx*mx)return 0;
	}
	return mul;
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		buc[a[i]]++;
		mx=max(mx,a[i]);
	}
	if(k==2){
		for(int i=1;i<=n;i++){
			tmp.clear();
			for(int j=2;j*j<=a[i];j++){
				if(a[i]%j==0){
					int yyy=0;
					while(a[i]%j==0)++yyy,a[i]/=j;
					if(yyy%2)tmp.push_back(j);
				}
			}
			if(a[i]>1)tmp.push_back(a[i]);
			ans+=mp[tmp];
			mp[tmp]++;
		}
		cout<<ans<<endl;
		return 0;
	}
	p=1;
	while(1){
		ll m=ok(p);
		if(!m)break;
		for(register ll i=1;i*i<=m;i++){
			if(m/i>mx||m%i)continue;
			if(i*i==m){
				ans+=buc[i]*(buc[i]-1)/2;
			}
			else{
				ans+=buc[i]*buc[m/i];
			}
		}
		p++;
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 2
4 9 9 16 1
*/