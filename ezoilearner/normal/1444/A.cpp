#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p,q;
#define Maxn

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>p>>q;
		if(p%q!=0)cout<<p<<endl;
		else{
			ll res=1;
			for(int i=2,u=q;i*i<=u;++i)
				if(q%i==0){
					int c1=0;
					while(q%i==0){
						q/=i;
						c1++;
					}
					ll pre=p;int c2=0;
					while(pre%i==0){
						pre/=i;
						c2++;
					}
					ll ans=p;
					for(int j=1;j<=c2-c1+1;++j)ans/=i;
					res=max(res,ans);
				}
			if(q>1){
				int c=0;
				ll pre=p;
				while(pre%q==0){
						pre/=q;
						c++;
					}
				ll ans=p;
				for(int j=1;j<=c;++j)ans/=q;
				res=max(res,ans);
			}
			cout<<res<<endl;
		}
	}
	return 0;
}