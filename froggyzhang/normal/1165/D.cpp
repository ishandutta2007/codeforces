#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define N 1010
typedef long long ll;
const ll mx=1e12;
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
int T,n;
map<ll,int> buc;
ll a[N],ans;
vector<ll> vec; 
void Check(ll x){
	for(ll i=2;i*i<=x;++i){
		if(x%i==0){
			int cnt=0;
			while(x%i==0)x/=i,++cnt;
			if(!buc.count(i))vec.push_back(i),buc[i]=cnt;
			else buc[i]=max(buc[i],cnt);
		}
	}
	if(x>1){
		if(!buc.count(x))vec.push_back(x),buc[x]=1;
	}
}
int Count(){
	int tot=1;
	for(int i=0;i<vec.size();++i){
		tot*=buc[vec[i]]+1;
	}
	return tot;
}
int main(){
	T=read();
	while(T--){
		n=read();
		vec.clear();
		buc.clear();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		if(a[1]<=1){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			Check(a[i]);
		}
		sort(vec.begin(),vec.end());
		ans=1;
		for(int i=0;i<vec.size();i++){
			if(ans>mx)break;
			int tp=buc[vec[i]];
			for(int j=1;j<=tp;++j){
				ans*=vec[i];
				if(ans>mx){
					break;
				}
			}
		}
		if(ans>mx){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;++i){
			if(ans==a[i]){
				ans*=vec[0];
				buc[vec[0]]++;
				break;
			}
		}
		if(Count()-2==n){
			printf("%lld\n",ans);
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}