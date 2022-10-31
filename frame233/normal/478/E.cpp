#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef unsigned int uint;typedef long long ll;
int a[15],top;
bool check(ll x,int len=-1){
	top=0;while(x)a[++top]=x%10,x/=10;
	while(top<len)a[++top]=0;
	bool flag=1;for(int i=2;i<top;++i)flag&=(a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[1+i]);
	return flag;
}
int v[850005],pos;
struct hash_table{
	static const int _mod=1000033;
	ll key[_mod+1];int v[_mod+1];
	hash_table(){memset(key,-1,sizeof(key));}
	void ins(ll KEY){
		uint x=KEY%_mod;while(key[x]!=-1&&key[x]!=KEY)++x;
		if(x==_mod){x=0;while(key[x]!=-1&&key[x]!=KEY)++x;}
		key[x]=KEY,++v[x];
	}
	int ask(ll KEY){
		uint x=KEY%_mod;while(key[x]!=-1&&key[x]!=KEY)++x;
		if(x==_mod){x=0;while(key[x]!=-1&&key[x]!=KEY)++x;}
		return key[x]==KEY?v[x]:0;
	}
}mp[10][2];
int main(){
	for(int i=0;i<10000000;++i)if(check(i,7))v[pos++]=i;
	ll n,k;read(n,k);
	for(int i=n;i<10000000;i+=n)if(check(i)&&(i>=100||i/10!=i%10)&&!--k)return printf("%d\n",i),0; // wtf???
	for(int i=0;i<pos;++i){
		int x=v[i]/1000000,y=v[i]/100000%10;
		mp[x][x>y].ins(v[i]%n);
	}
	for(int i=1;i<10000000;++i)if(check(i)){
		int l=0,r=9,x=i%10;
		if(i>=10){int y=i/10%10;if(x>y)r=x-1;else if(x<y)l=x+1;else continue;}
		ll tmp=(10000000LL*i)%n;
		for(int c=l;c<=r;++c)if(c!=x){
			ll cnt=mp[c][c>x].ask(tmp==0?0:n-tmp);
			if(k<=cnt){
				int o=c>x;
				for(int j=0;j<pos;++j){
					int x=v[j]/1000000,y=v[j]/100000%10;if(x!=c||(x>y)!=o)continue;
					ll val=10000000LL*i+v[j];if(val%n==0&&check(val)&&!--k)return printf("%lld\n",val>1e14?-1:val),0;
				}
				assert(0);
			}
			else k-=cnt;
		}
	}
	puts("-1");
	return 0;
}